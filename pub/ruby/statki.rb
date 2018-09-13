#!/usr/bin/env ruby

require "socket"
require "rubygame"
include Rubygame
include Rubygame::Events
include Rubygame::EventActions
include Rubygame::EventTriggers
include EventHandler::HasEventHandler

#wyswietlaj bledy na konsole
$stdout.sync = true

Rubygame.init()

# SDL_gfx jest potrzebne do rysowania Surfaces 
$gfx_ok = (VERSIONS[:sdl_gfx] != nil)

unless ( $gfx_ok )
	raise "Musisz miec SDL_gfx!"
end

# pobiera aktualna rozdzielczosc
$res = Screen.get_resolution()

#tworzy 'ekran' o pobranej wczesniej rozdzielczosci
screen = Screen.open($res,0,flags=[SDL::HWSURFACE,FULLSCREEN])
#niektore inne flagi: RESIZABLE FULLSCREEN HWSURFACE ASYNCBLIT OPENGL NOFRAME
screen.title = "Sieciowa gra w statki"

#opcja skalowania obrazu, wlaczenie moze znacznie pogorszyc wydajnosc!!!
#defaultowa rozdzielczosc - 1024x768
$skalowanie = false 
if $skalowanie
	$skala = Array.new(2) 
	$skala[0] = 1024.to_f / $res[0].to_f
	$skala[1] = 768.to_f / $res[1].to_f
end

#nazwa serwera
$serwer = nil

#stan gry
$tab = Array.new(100,0)
$tabw = Array.new(100,0)

#bufor obrazu, tutaj jest defaultowa rozdzielczosc 
pic = Surface.new( [1024,768] )

#kolejka ze zdarzeniami
queue = EventQueue.new()
queue.enable_new_style_events()
queue.ignore = [ActiveEvent,MouseUpEvent,MouseDownEvent]

#zegarek opozniajacy petle obslugi zdarzen
clock = Clock.new();
#tylko 10 bo brak animacji a ewentualne skalowanie jest niewydajne
clock.target_framerate = 10
clock.calibrate
clock.enable_tick_events

#metody rysowania planszy
module Plansza

	#rysuje plansze dafaultowo swoja
	def draw (t = $tab)
		pic = Surface.new( [500,500] )
		
		#siatka
		for a in 0..11 do
			b = a*50
			if b == 500
				b-=1
			end
			pic.draw_line([0,b],[499,b],[255,255,0])
			pic.draw_line([b,0],[b,499],[255,255,0])
		end
		
		#zapelnia pola
		for c in 0..9 do
			for d in 0..9 do
				e = t[c+d*10]
				case e
					when 0 #pusto
						pic.draw_line_a([c*50+24,d*50+24],[c*50+24,d*50+24],[0,0,255])
					when 10..20 #maszt
						pic.draw_circle_a([c*50+24,d*50+24],10,[0,255,0])
						pic.draw_box([c*50+9,d*50+9],[c*50+39,d*50+39],[0,255,0])
					when 2 #pudlo
						pic.draw_line_a([c*50+14,d*50+14],[c*50+36,d*50+36],[255,0,0])
						pic.draw_line_a([c*50+36,d*50+14],[c*50+14,d*50+36],[255,0,0])
					when 20..30 #trafiony
						pic.draw_line_a([c*50+14,d*50+14],[c*50+36,d*50+36],[255,0,0])
						pic.draw_line_a([c*50+36,d*50+14],[c*50+14,d*50+36],[255,0,0])
						pic.draw_circle_s([c*50+24,d*50+24],7,[255,0,0])
					when 4 #zatopiony
						pic.draw_line_a([c*50+14,d*50+14],[c*50+36,d*50+36],[255,0,0])
						pic.draw_line_a([c*50+36,d*50+14],[c*50+14,d*50+36],[255,0,0])
						pic.draw_circle_s([c*50+24,d*50+24],7,[255,0,0])
						pic.draw_box([c*50+9,d*50+9],[c*50+40,d*50+40],[255,0,0])
					when 5..6 #zaznaczony
						pic.draw_circle_s([c*50+24,d*50+24],7,[255,0,0])																								
					else #awaria
						pic.draw_circle_s([c*50+24,d*50+24],7,[255,255,255])
				end
			end
		end
		
		return pic
	end

end


#klasa z elementami do obslugi ekranu i zdarzen
class Ekran

	def initialize (screen,pic,queue,clock)
	
		@queue = queue
		@clock = clock
		@screen = screen
		@pic = pic
		
		draw_nic
		zdarzenia
		step
	
	end

	#haczyki do zdarzen
	def zdarzenia			
		hooks = {
		MouseMoved => proc { |owner, event| zaznacz(event.pos) },
		KeyPressed => proc { |owner, event| click(event.string) },
		}
		make_magic_hooks( hooks )
	end

	#nieskonczona petla zdarzen
	def step 
	catch(:quit) do
			loop do
				@queue.fetch_sdl_events
				@queue << @clock.tick
				@queue.each do |event|
				handle( event )
				end
				redraw
			end
		end		
	end

	#przerysowuje ekran
	def redraw ()
		if @pic.respond_to?(:zoom) && $skalowanie
			@pic.zoom_to($res[0],$res[1],true).blit(@screen,[0,0])
		else
			@pic.blit(@screen,[0,0])
		end		
		@screen.update()		
	end
	
	#czysci ekran
	def draw_nic ()
		@pic.draw_box_s([0,0],[1023,763],[0,0,0])
		@pic.blit(@screen,[0,0])
	end  

	#rysuje tekst
	def render_txt( obraz , tekst, pozycja, rozmiar)
		TTF.setup()
		ttfont_path = File.join(File.dirname(__FILE__),"FreeSans.ttf")
		ttfont = TTF.new( ttfont_path, rozmiar )
		result = ttfont.render( tekst, true, [250,250,250] )
		result.blit( obraz, pozycja )
	end
	
	#przelicza wspolzedne kursora w zaleznosci od rozdzielczosci
	def skala(xy)

		b = Array.new(2,0)
		
		if $skalowanie

			b[0] = (xy[0] * $skala[0]).to_i 
			b[1] = (xy[1] * $skala[1]).to_i 
			return b
		else
			return xy
		end 
			
	end	

	#...
	def quit
		throw :quit
	end

end


#wlasciwa funkcjonalnosc gry
class Gra < Ekran

include Plansza

	def initialize (screen,pic,queue,clock)
	
		@queue = queue
		@clock = clock
		@screen = screen
		@pic = pic
		
		#zmienne pomocnicze do wspolzednych
		@x = 0
		@y = 0
		#socket
		@s = nil
		#blokada klikania
		@blokada = false
		#blokada okna informacyjnego
		@lock = true
		@stop = false
		
		hooks_set={
		MousePressed => proc { |owner, event| ruch(event.pos,event.button,self) },
		MouseMoved => proc { |owner, event| zaznacz(event.pos) },
		KeyPressed => proc { |owner, event| klik(event.string) },
		}
		make_magic_hooks( hooks_set )

    #polaczenie w watku 
    a1 = Thread.new {
		
		begin
		
			#laczenie z przeciwnikiem
			if $serwer == nil
				draw_msg("OCZEKIWANIE NA KLIENTA...")
				server = TCPServer.open(4567) 
				@s = server.accept  
				draw_nic
				draw_gra
				redraw
				draw_msg("STRZELAJ!")  
				@blokada = true
			else
				@blokada = false
				draw_msg("OCZEKIWANIE NA SERWER...")
				@s = TCPSocket.open($serwer,4567)
				draw_msg("CZEKAJ....");
			
				#fragment metody ruch dla gracza ktory pozniej zaczyna
				
				line = @s.gets

				odp = $tab[line.to_i]
				if odp == 0
					odp = 2
				else
					odp += 10
				end
			
				@s.puts(odp)
		
				$tab[line.to_i] = odp
		
				zatapiaj
				
				draw_nic
				draw_gra
				redraw
				draw_msg("STRZELAJ!")
				@blokada = true
			end 

		rescue
		
			while @lock
				@stop = true
				problem
				@queue.each do |event|
					handle( event )
				end
			end
			@lock = true
			@stop = false
			retry
		end
			} 
			a1.run
		step
	end

	#obsluga zdarzen i odswiezanie obrazu
    	def step 
			catch(:quit) do
				loop do
					@queue.fetch_sdl_events
					@queue << @clock.tick
					@queue.each do |event|
					handle( event )
				end
				if !@stop
					redraw
				end
			end
		end		
	end

	#komunikat bledu polaczenia
	def problem
		draw_nic
		render_txt(@pic,"BRAK KONTAKTU!!!",[100,130],80)
		@pic.draw_box([150,300],[950,400],[255,255,255])
		@pic.draw_box([150,450],[950,550],[255,255,255])
		render_txt(@pic,"SPACJA - JESZCZE RAZ",[160,320],50)
		render_txt(@pic,"Q      - KONIEC",[160,470],50)		
		redraw
	end
	
	#zdarzenie klikniecia klawisza
	def klik(k)
		if k[0] != nil
			if k[0].ord == 32
				@lock = false
			end
			if k[0].ord == 113
				if @s != nil
					@s.close
				end
				quit
			end
		end
	end

	#wyswietlanie informacji u dolu ekranu
	def draw_msg ( t )
		@pic.draw_box_s([0,610],[700,680],[0,0,0])
		render_txt(@pic,t,[10,625],40)
		redraw
	end
	
	#rysuje ekran gry
	def draw_gra
		draw.blit(@pic,[7,100])
		draw($tabw).blit(@pic,[517,100])
		render_txt(@pic,"Ty",[10,10],40)
		render_txt(@pic,"Przeciwnik",[530,10],40)
		@pic.draw_box([1,700],[1023,762],[255,255,255])
		render_txt(@pic,"KONIEC - Q",[450,705],40)
	end

	#zaznacza pole pod kursorem
	def zaznacz(xy)
		
		xy = skala(xy)

		if @blokada
			a = (xy[0]-517).abs/50
			b = (xy[1]-100).abs/50

			#jezeli wspolzedne sie zmienily		
			if (a != @x || b != @y)
				#jezeli wspolzedne sa na planszy
				if (xy[0] > 517 && xy[0] < 1017 && xy[1] > 100 && xy[1] < 600)
					
					#usuwa wczesniejsze zaznaczenia, da sie lapiej to zrobic
					for i in 0..99 do
						if $tabw[i] == 5
							$tabw[i]=0
						end
					end
			
					if $tabw[a+b*10] == 0
						$tabw[a+b*10] = 5
					end
					@x=a
					@y=b
					draw_gra
				end
			end
		end
	end

	#akcja klikniecia przycisku myszy
	def ruch (xy,b,c)

		#przycisk KONIEC
		if xy[1] > 700 
			quit
		end

		#ustawianie statku
		if @blokada && b == :mouse_left 

			i = @x+@y*10
		
			a = Thread.new {
			begin
				#jezeli mozna tu strzelic
				if $tabw[i] == 5
					$tabw[i]= 6
			
				
					@blokada = false
					draw_msg("CZEKAJ...")
			
					#wysylam strzal
					@s.puts(i.to_s+"\n")
			
					#odbieram odpowiedz
					line = @s.gets
			
					#wpisuje na tablice wroga
					########################
					$tabw[i] = line.to_i
					
					sprw
					zatapiaj
					draw_gra
					redraw

					zatapiaj
					draw_gra
					redraw
				
					#odbieram strzal
					line = @s.gets
			
					#wysylam odpowiedz
					#######################
					odp = $tab[line.to_i]
					if odp == 0
						odp = 2
					else
						odp += 10
					end
			
					@s.puts(odp)
			
					$tab[line.to_i] = odp
					
					zatapiaj
					draw_gra
					redraw
					@blokada = true
					draw_msg("STRZELAJ!")
					sprw
				end
							
				
			rescue
				
				while @lock
					@stop = true
					problem
					@queue.each do |event|
						handle( event )
					end
				end
				@stop = false
				@lock = true
				retry
			end
			} 
			a.run
		end
	end

	#zamienia 'trafione' w calosci statki na zatopione 
	#malo opymalne
	def zatapiaj ( )
		tmp = Array.new(10,0)
		tmpw = Array.new(10,0)
		x = 0
		y = 0
		
		for i in 0..99 do
			j = $tab[i]
			if j > 20
				tmp[j-20] += 1 
			end
		end

		for i in 0..99 do
			j = $tabw[i]
			if j > 20
				tmpw[j-20] += 1 
			end
		end

		x = spr(tmp)
		y = spr(tmpw)
		
		if x > 0
			for i in 0..99 do
				if $tab[i] == x+20
					$tab[i] = 4 
				end
			end
		end
		
		if y > 0
			for i in 0..99 do
				if $tabw[i] == y+20
					$tabw[i] = 4 
				end
			end
		end
		
	end
	
	#potrzebne do zatapiania
	def spr (tmp)
		a = 0
		if tmp[1] == 1 
			a = 1
		end
		if tmp[2] == 1
			a = 2
		end			
		if tmp[3] == 2 
			a = 3
		end			
		if tmp[4] == 2 
			a = 4
		end	
		if tmp[5] == 3 
			a = 5
		end	
		if tmp[6] == 4
			a = 6
		end	
		if tmp[7] == 5
			a = 7
		end	
		return a
	end
	
	#sprawdza czy wygrana/przegrana
	#malo optymalne
	def sprw
		
		w=0
		p=0
		

		for i in 0..99 do
			if $tabw[i] > 20 || $tabw[i] == 4
				w +=1
			end
			if $tab[i] > 20 || $tab[i] == 4
				p +=1
			end
		end

		if w == 18
			msg("WYGRANA :)")
		end
		if p == 18
			msg("PRZEGRANA :(")
		end
	end
	
	#wyswietla komunikat podczas gry
	def msg (tekst)
		@stop = true
		while true
			draw_nic
			render_txt(@pic,tekst,[100,130],80)
			render_txt(@pic,"Q      - KONIEC",[160,470],50)		
			redraw
				
			@queue.each do |event|
					handle( event )
				end
		end
	end

end

#klasa ma udostepniac ladne GUI do laczenia sie z serwerem
class Menu < Ekran

	def initialize (screen,pic,queue,clock)
		
		@queue = queue
		@clock = clock
		@screen = screen
		@pic = pic	
		
		#aktywny ekran menu
		@actW = 0
		#pobrananazwa serwera
		@name = ""	
		
		hooks={
		MousePressed => proc { |owner, event| clickM(event.pos,event.button) },
		KeyPressed => proc { |owner, event| click(event.string) },
		}
		make_magic_hooks( hooks )
	
		#rysuje menu
		draw_nic
		render_txt(@pic,"SIECIOWA GRA W STATKI",[10,130],80)
		render_txt(@pic,"Autor: Marcin Nowak indeks: 275155 nietamten@gmail.com",[10,720],20)
		@pic.draw_box([250,300],[750,400],[255,255,255])
		@pic.draw_box([250,450],[750,550],[255,255,255])
		@pic.draw_box([250,600],[750,700],[255,255,255])
		render_txt(@pic,"KLIENT",[400,320],50)
		render_txt(@pic,"SERWER",[400,470],50)
		render_txt(@pic,"KONIEC",[400,620],50)
		redraw
		step
	end

	#klikniecie myszki
	def clickM(xy,b)
		
		xy = skala (xy)

		if @actW == 0
			#przycisk klient
			if xy[0]>250 && xy[0]<750 && xy[1]>300 && xy[1]<400
				draw_nic
				draw_m
				@actW = 1
			end
			#przycisk serwer
			if xy[0]>250 && xy[0]<750 && xy[1]>450 && xy[1]<550
				$serwer = nil
				draw_nic
				Ustaw.new(@screen,@pic,@queue,@clock)
				quit
			end
			#przycisk koniec
			if xy[0]>250 && xy[0]<750 && xy[1]>600 && xy[1]<700
				quit
			end
		end
	end

	#klikniecie klawiatury
	def click (k)

		if k[0]!= nil
			ky = k[0].ord

			if @actW == 1	

				#jak nie enter to pobieraj znaki
				if ky != 13
					if ky == 8 			
						if @name.length != 1
							@name = @name [0..@name.length-2]
						else
							@name.clear
						end
					else
						@name += k
					end				
					draw_n
				else
					$serwer=@name
					draw_nic
					$x=1					
					quit
				end
			end
		end
	end

	#wyswietla ekran 'wpisz adres'
	def draw_m
		draw_nic
		render_txt(@pic,"WPISZ ADRES",[400,200],50)
		@pic.draw_box_s([300,300],[1000,500],[0,0,0])
		render_txt(@pic,"i nacisnij enter",[400,600],50)
		redraw
	end
	
	#wyswietla/odswieza adres
	def draw_n		
		@pic.draw_box_s([300,300],[1000,500],[0,0,0])
		if @name != ""
			render_txt(@pic,@name,[400,400],50)			
		end
		redraw
	end

end

#ustawnianie statkow
class Ustaw < Ekran

	include Plansza
	
	attr_accessor :jak

	def initialize (screen,pic,queue,clock)
	
		@queue = queue
		@clock = clock
		@screen = screen
		@pic = pic
		
		#ilomasztowiec aktualnie ustawiany
		@ile = 1
		#czy ma byc poziomo czy pionowo
		@jak = 1
		#ile juz takich postawiono
		@ile2 = 0
		#ile statkow ogulem
		@ile3 = 0

		draw_ustaw
	
		draw.blit(@pic,[100,100])
		zdarzenia
		step
		
	end
	
	#w osobnej metodzie bo inaczej specyficzny blad
	def zdarzenia			
		hooks={
		MousePressed => proc { |owner, event| click(event.pos,event.button,self) },
		MouseMoved => proc { |owner, event| zaznacz(event.pos) },
		}
		make_magic_hooks( hooks )
	end

	#akcja klikniecia myszki
	def click (xy,b,c)

		xy = skala(xy)
		
		#przycisk KONIEC
		if xy[1] > 700
			quit
		end
	
		#obracanie
		if b == :mouse_right
			if c.jak == 0
				c.jak = 1
			else
				c.jak = 0
			end
			zaznacz(xy)
		end
	
		#ustawianie statku
		if b == :mouse_left && @h == 0 
			c.postaw
		end

	end
    
	#zaznacza statki na planszy pod kursorem
	#odpowiada za odswiezanie planszy na ekranie ustawiania statkow
	def zaznacz(xy)

		xy = skala(xy)

		#przeliczanie wspolzednych kursora na pozycje planszy
		a = (xy[0]-100).abs/50
		b = (xy[1]-100).abs/50

		#jezeli wspolzedne sie zmienily		
		if (a != @x || b != @y)
			#jezeli wspolzedne sa na planszy
			if (xy[0] > 100 && xy[0] < 600 && xy[1] > 100 && xy[1] < 600)
				#jezeli statek sie miesci od tej wspolzednej (zalezne od @jak - poziomo/pionowwo)
				if (@jak == 1) && (a < 11-@ile) || (@jak == 0) && (b < 11-@ile)
					
					
					#usuwa wczesniejsze zaznaczenia, da sie lapiej to zrobic
					for i in 0..99 do
						if $tab[i] == 5
							$tab[i]=0
						end
					end
				
					#sprawdza czy statek pasuje (nie nachodzi na inny)
					@h = 0
						if @jak == 1
							for q in 0..@ile-1
								if $tab[q+a+b*10] > 10 && $tab[q+a+b*10] < 20
									@h = 1
								end
							end
						else
							for q in 0..@ile-1
								if $tab[a+(b+q)*10] > 10 && $tab[a+(b+q)*10] < 20
									@h = 1
								end
							end

						end				
				
				
					#zaznacza nowe
					if @h == 0
						for q in 0..@ile-1	
							if @jak == 1
								$tab[q+a+b*10] = 5
							else
								$tab[a+(b+q)*10] = 5
							end
						end					
					end
				
					@x=a
					@y=b

					draw.blit(@pic,[100,100])

				end
			end
		end
	end
	
 #zamienia 'zaznaczenia' na 'maszty' 
 #i liczy ile postawiono
	def postaw
			@ile3 += 1

			for i in 0..99 do
				if $tab[i] == 5
					$tab[i]=@ile3+10
				end
			end

			@ile2 += 1
		
			if (@ile == 1 || @ile == 2) && (@ile2 == 2)
				@ile+=1
				@ile2=0
			end
			if (@ile == 3 || @ile == 4) && (@ile2 == 1)
				@ile+=1
				@ile2=0
			end		
			if @ile == 5 && @ile2 == 1
				$x=2
				draw.blit(@pic,[100,100])
				quit
			end
	end
		
	#rysuje detale ekranu ustawiania
	def draw_ustaw
		@pic.draw_box([1,700],[1023,762],[255,255,255])
		render_txt(@pic,"KONIEC",[450,705],40)
		render_txt(@pic,"USTAW STATKI",[20,20],40)
		@pic.draw_ellipse_a([800,600],[50,70],[255,255,255])
		@pic.draw_line_a([754,575],[846,575],[255,255,255])
		@pic.draw_line_a([800,530],[800,575],[255,255,255])
		render_txt(@pic,"USTAWIA",[660,540],20)
		render_txt(@pic,"OBRACA",[850,540],20)	
		render_txt(@pic,"LEGENDA:",[640,60],30)
		@pic.draw_box([950,115],[1000,165],[255,255,0])
		@pic.draw_line_a([974,139],[974,139],[0,0,255])
		render_txt(@pic,"PUSTE POLE",[660,125],20)
		@pic.draw_box([950,185],[1000,235],[255,255,0])
		@pic.draw_circle_a([974,209],10,[0,255,0])
		@pic.draw_box([959,194],[989,224],[0,255,0])
		@pic.draw_box([950,255],[1000,305],[255,255,0])	
		@pic.draw_line_a([964,269],[986,291],[255,0,0])
		@pic.draw_line_a([986,269],[964,291],[255,0,0])	
		@pic.draw_box([950,325],[1000,375],[255,255,0])
		@pic.draw_line_a([964,339],[986,361],[255,0,0])
		@pic.draw_line_a([986,339],[964,361],[255,0,0])
		@pic.draw_circle_s([974,349],7,[255,0,0])
		@pic.draw_box([950,395],[1000,445],[255,255,0])
		@pic.draw_line_a([964,409],[986,431],[255,0,0])
		@pic.draw_line_a([986,409],[964,431],[255,0,0])
		@pic.draw_circle_s([974,419],7,[255,0,0])
		@pic.draw_box([959,404],[990,435],[255,0,0])
		@pic.draw_box([950,465],[1000,515],[255,255,0])
		@pic.draw_circle_s([974,489],7,[255,0,0])
		@pic.draw_line_a([974,139],[974,139],[0,0,255])
		render_txt(@pic,"MASZT",[660,195],20)
		render_txt(@pic,"NIETRAFIONY",[660,265],20)
		render_txt(@pic,"TRAFIONY",[660,335],20)
		render_txt(@pic,"ZATOPIONY",[660,405],20)
		render_txt(@pic,"ZAZNACZONY",[660,475],20)	
	end
	
end

###############
#potrzebne!####
###############
$x = 0
catch(:quit) do
	#menu
    Menu.new(screen,pic,queue,clock)
	if $x == 1
	#ustawianie statkow
		Ustaw.new(screen,pic,queue,clock)
	end
	if $x == 2
	#granie
		Gra.new(screen,pic,queue,clock)
	end

end
