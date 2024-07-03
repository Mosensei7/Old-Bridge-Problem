# Old Bridge Problem
I.	Description of the problem: The Old Bridge Problem is also known as the Crossing the Bridge Problem classic synchronization challenge in concurrent programming. It involves managing access to a single-lane bridge where only one direction of traffic can cross at a time, and often there’s a limit to the number of vehicles that can be on the bridge simultaneously.
II.	The problems we encountered during the solving:
I.	Utilizing the Semaphore Library is only available  in C20 or Later so if we depend on this library most of our solving  won’t be workable on many systems. 

II.	We struggled in our solution because we made a mistake by placing unique_lock inside loop itself 

III.	The issue arises in synchronizing vehicle movement without causing data races or deadlocks. Without adequate synchronization, the following concerns may arise:

Data Race: If many threads representing vehicles attempt to access the bridge at the same time, they may overwrite the current state (for example, the number of vehicles on the bridge), causing inconsistencies.
Deadlock: If two cars (one light and one heavy) collide on a bridge, they may become stuck, waiting for the other to leave while neither can move.
The Solution of the Problem:
Several synchronization techniques can be used to solve the Old Bridge Problem:
•	Mutex: A single mutex can be used to control access to the bridge. Only one thread (vehicle) can acquire the mutex at a time, ensuring mutual exclusion and preventing overloading.
•	Semaphores: Two semaphores can be used, one for light vehicles and one for heavy vehicles. Each semaphore controls the number of vehicles of its type allowed on the bridge, ensuring both mutual exclusion and fairness.
•	Atomic Operations: Languages that support atomic operations can be used to update the bridge state (e.g., the number of vehicles on it) atomically, preventing data races.
## You can adjust the limit of the cars that they're passing.
# Runtime screenshoot. 
![image](https://github.com/Mosensei7/Old-Bridge-Problem/assets/111107874/e1a2bf25-8dd4-4f10-9427-788c2e6ebaf0)
