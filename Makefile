

all: drasil menu nexus sfml

drasil:
		cd Drasil/build ; cmake .. -G "Unix Makefiles" ; make ; cd -

drasil_clean:
		cd Drasil/build ; make clean ; cd -

menu:
		cd Games/Menu/build ; cmake .. -G "Unix Makefiles" ; make ; cd -

menu_clean:
		cd Games/Menu/build ; make clean ; cd -


nexus:
		cd Nexus/build ; cmake .. -G "Unix Makefiles" ; make ; cd -

nexus_clean:
		cd Nexus/build ; make clean ; cd -

sfml:
		cd Graphicals/SFML/build ; cmake .. -G "Unix Makefiles" ; make ; cd -

sfml_clean:
		cd Graphicals/SFML/build ; make clean ; cd -

clean: menu_clean drasil_clean nexus_clean sfml_clean 

re: clean drasil menu nexus sfml