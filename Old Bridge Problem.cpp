#include<bits/stdc++.h>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;
const int MAX_CARS = 3; // Maximum cars allowed on the bridge
int cars_on_bridge = 0;
int current_direction = -1; // -1 indicates no direction is set
std::mutex bridge_mutex;
std::condition_variable bridge_condition;

void ArriveBridge(int id, int direction) {
    std::unique_lock<std::mutex> lock(bridge_mutex);
    while ((current_direction != -1 && current_direction != direction) || cars_on_bridge == MAX_CARS) {
        // Wait until the bridge is empty or cars in the same direction are crossing
        bridge_condition.wait(lock);
    }
    current_direction = direction;
    cars_on_bridge++;
    std::cout << "Car " << id << " is crossing the bridge in direction " << direction << std::endl;
}

void ExitBridge(int id, int direction) {
    std::unique_lock<std::mutex> lock(bridge_mutex);
    cars_on_bridge--;
    if (cars_on_bridge == 0) {
        current_direction = -1;
        // Notify all waiting cars since the bridge is now empty
        bridge_condition.notify_all();
    }
    else {
        // Notify one car in the same direction
        bridge_condition.notify_one();
    }
    std::cout << "Car " << id << " has exited the bridge in direction " << direction << std::endl;
}

void Car(int id, int direction) {
    ArriveBridge(id, direction);
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate crossing time
    ExitBridge(id, direction);
}

int main() {
    std::vector<std::thread> cars;
    // Create and start threads (cars)
    for (int i = 0; i < 10; ++i) {
        cars.push_back(std::thread(Car, i, i % 2));
    }
    // Join threads with the main thread
    for (auto& car : cars) {
        car.join();
    }
    //car [i] = 
    return 0;
}