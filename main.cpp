#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <vector>

std::vector<sf::RectangleShape> createRandomRectangles(){
    std::vector<sf::RectangleShape> rectangles;
    srand(time(NULL));
    
    for(size_t i = 0; i < 40; i++){
        size_t randomNum = rand() % 600 + 1; // 1 - 600
        auto rectangle = sf::RectangleShape(sf::Vector2f(15, randomNum));
        std::cout << randomNum << std::endl;
        rectangle.setFillColor(sf::Color::White);
        rectangle.setOutlineThickness(5);
        rectangle.setOutlineColor(sf::Color::Green);
        rectangles.push_back(rectangle);
    }
    return rectangles;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sorting Visualization");
    std::vector<sf::RectangleShape> rectangles = createRandomRectangles();

    //std::cout << rectangles.size();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        window.setFramerateLimit(60);

        // draw everything here...
        // window.draw(...);
        
        for(size_t i = 0; i < rectangles.size(); i++){
            rectangles[i].setPosition(i * 20 + 5, 0);
            window.draw(rectangles[i]);
        }

        // end the current frame
        window.display();
    }

    return 0;
}