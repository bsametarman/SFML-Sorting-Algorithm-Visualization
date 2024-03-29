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

void insertionSort(std::vector<sf::RectangleShape>& rectangles){
    for(size_t i = 1; i < rectangles.size(); i++){
        sf::RectangleShape key = rectangles[i];
        int j = i - 1;
        while(j >= 0 && rectangles[j].getSize().y > key.getSize().y){
            rectangles[j].setFillColor(sf::Color::Yellow);
            rectangles[j + 1] = rectangles[j];
            j--;
            break;
        }
        rectangles[j + 1] = key;
    }
}

void merge(std::vector<sf::RectangleShape>& rectangles, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<sf::RectangleShape> leftArray, rightArray;

    for(int i = 0; i < n1; i++)
        leftArray.push_back(rectangles[left + i]);
    for(int j = 0; j < n2; j++)
        rightArray.push_back(rectangles[mid + 1 + j]);

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2){
        if(leftArray[i].getSize().y <= rightArray[j].getSize().y){
            rectangles[k] = leftArray[i];
            i++;
        }
        else{
            rectangles[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        rectangles[k] = leftArray[i];
        i++;
        k++;
    }

    while(j < n2){
        rectangles[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<sf::RectangleShape>& rectangles, int left, int right){
    if(left >= right){
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(rectangles, left, mid);
    mergeSort(rectangles, mid + 1, right);
    merge(rectangles, left, mid, right);
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

        //bubbleSort(rectangles);
        selectionSort(rectangles);
        //insertionSort(rectangles);
        //mergeSort(rectangles, 0, rectangles.size() - 1); // sorting instantly, workin on it

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