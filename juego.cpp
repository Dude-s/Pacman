#include "juego.h"

juego::juego(int resolucion_x,int resolucion_y, string titulo){
	Vector2f pos(300,300);
	spritePosition=pos;
	fps=60;
	ventana1 = new RenderWindow(VideoMode(resolucion_x,resolucion_y),titulo);
	//spritePosition(300, 300);
	spriteIndex = 0;
	ventana1->setFramerateLimit(fps);
	//dibujar_pantalla();
	
	
	//mapa = new Texture;
	mapa.loadFromFile("mapa.png");

    	// Crear el sprite
    	
    	//smapa = new Sprite;
	smapa.setTexture(mapa);
       	//EStablece el tamano del mapa
    	smapa.setScale(1.2f, 1.2f);
	// Establecer la posición inicial del sprite en la parte inferior derecha de la ventana
    	smapa.setPosition(smapa.getPosition().x+100,smapa.getPosition().y+125);
	
	
	
	
	//pac1 = new Texture;
	pac1.loadFromFile("pac1.png");	
	//pac2 = new Texture;
	pac2.loadFromFile("pac2.png");	
	//pac3 = new Texture;
	pac3.loadFromFile("pac3.png");	
	
	
	//spac1 = new Sprite;
	spac1.setTexture(pac1);
	//spac2 = new Sprite;
	spac2.setTexture(pac2);
	//spac3 = new Sprite;
	spac3.setTexture(pac3);
	
	spac1.setScale(0.5f,0.5f);
    	spac2.setScale(0.5f,0.5f);
    	spac3.setScale(0.5f,0.5f);
    	
    	//evento1 = new Event;
	llenar_cords();
	crear_colisiones();
	
			
	gameLoop();


}

void juego::dibujar_pantalla()
{    	
	ventana1->clear();
	
	ventana1->draw(smapa);
	
	for (auto& colision : colisiones)
        {
            ventana1->draw(colision);
        }
	
        if (clock.getElapsedTime().asMilliseconds() > 50) {
            spriteIndex = (spriteIndex + 1) % 3;
            clock.restart();
        }
        if (spriteIndex == 0){
            spac1.setPosition(spritePosition);
            ventana1->draw(spac1);}
        else if(spriteIndex== 1){
            spac2.setPosition(spritePosition);
            ventana1->draw(spac2);
            }
        else{
            spac3.setPosition(spritePosition);
            ventana1->draw(spac3);
            }
	
	ventana1->display();


}

void juego::gameLoop(){

	while(ventana1->isOpen()){
		
		
		procesar_eventos();
		dibujar_pantalla();	
		
	}


}

void juego::llenar_cords(){

	tamano={{660,16},{15,730},{660,11},{11,730},{131,252},{133,252},{38,110},{60,36},{60,36}};
	
	cords={{105,130},{105,130},{105,850},{753,130},{635,348},{105,348},{417,130},{105,708},{706,708}};


}

void juego::crear_colisiones(){

	// Crear 30 colisiones aleatorias
	for (int i = 0; i < 9; i++)
    	{
        	// Crear un rectángulo con una posición y tamaño aleatorios
        	RectangleShape colision(Vector2f(tamano[i].first,tamano[i].second));
        	colision.setPosition(cords[i].first, cords[i].second);
        	colision.setFillColor(Color::Transparent);
        	colision.setOutlineThickness(1);
    		colision.setOutlineColor(Color::Red);

        	// Agregar el rectángulo al vector de colisiones
        	colisiones.push_back(colision);
    	}

}


void juego::procesar_eventos(){
	while (ventana1->pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                ventana1->close();
            }
        }
        // Mover personaje con las teclas de flecha
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            //spacman.move(-1, 0);
            spritePosition.x -= 1;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            //spacman.move(1, 0);
            spritePosition.x += 1;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            //spacman.move(0, -1);
            spritePosition.y -= 1;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            //spacman.move(0, 1);
            spritePosition.y += 1;
        }



}

