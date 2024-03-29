#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <vector>

std::vector<sf::RectangleShape> createRandomRectangles(){
    std::vector<sf::RectangleShape> rectangles;
    srand(time(NULL));
    
    for(size_t i = 0; i < 80; i++){
        int randomNum = rand() % 600 + 1; // 1 - 600
        auto rectangle = sf::RectangleShape(sf::Vector2f(5, randomNum));
        std::cout << randomNum << std::endl;
        rectangle.setFillColor(sf::Color::White);
        rectangle.setOutlineThickness(5);
        rectangle.setOutlineColor(sf::Color::Green);
        rectangles.push_back(rectangle);
    }
    return rectangles;
}

void bubbleSort(std::vector<sf::RectangleShape>& rectangles){
    for(size_t i = 0; i < rectangles.size() - 1; i++){
        for(size_t j = 0; j < rectangles.size() - i - 1; j++){
            if(rectangles[j].getSize().y > rectangles[j + 1].getSize().y){
                rectangles[j].setFillColor(sf::Color::Yellow);
                rectangles[j + 1].setFillColor(sf::Color::Red);
                std::swap(rectangles[j], rectangles[j + 1]);
                break;
            }
        }
        break;
    }
}

void selectionSort(std::vector<sf::RectangleShape>& rectangles){ 
    int minIndex; 
    for(size_t i = 0; i < rectangles.size() - 1; i++){ 
        minIndex = i; 
        for (size_t j = i + 1; j < rectangles.size(); j++){ 
            if(rectangles[j].getSize().y < rectangles[minIndex].getSize().y) 
                minIndex = j; 
        } 
        if(minIndex != i){
            rectangles[minIndex].setFillColor(sf::Color::Yellow);
            rectangles[i].setFillColor(sf::Color::Red);
            std::swap(rectangles[minIndex], rectangles[i]);
            break;
        }
    } 
}

void setColorToWhite(std::vector<sf::RectangleShape>& rectangles){
    for(auto& rectangle : rectangles)
        rectangle.setFillColor(sf::Color::White);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sorting Visualization");
    std::vector<sf::RectangleShape> rectangles = createRandomRectangles();
    sf::Time sleepTime = sf::seconds(0.1);

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

        bubbleSort(rectangles);
        //selectionSort(rectangles);

        for (size_t i = 0; i < rectangles.size(); i++) {
            rectangles[i].setPosition(i * 10 + 5, 600 - rectangles[i].getSize().y);
            window.draw(rectangles[i]);
        }
        // end the current frame
        window.display();

        sf::sleep(sleepTime);

        setColorToWhite(rectangles);
    }

    return 0;
}