# Pulsar Physics-engine
## Description
This physics engine uses verlet integration to solve the position of each sphere. By using this method, we can simply move one object, and the verlet integration will automatically solve the dynamics for us!
## Showcase
https://github.com/4o4hasfound/Physics-engine/assets/138118407/e20aa58b-fc74-49c9-a409-cb23389d2f54

## Code Example
### Basic Usage
```c++
using namespace Pulsar;
PhysicsWorld world(vec2(0.0f, 9.8f)); // Declare the world and set the gravity

// BodyDef objects can be reused to create multiple Body
BodyDef settings(Sphere);  // Set the settings for a sphere Body
settings.type = RigidBody; // Set the body type for the sphere Body
settings.position = vec2(0, 0);
settings.acceleration = vec2(0.0, 100000.0);
settings.bodyData.Radius = 10.0f; // Set the radius for the sphere Body

Body* body = world.createBody(&settings); // Create the body
Collider* collider = new SphereCollider(10.0f); // Create the collider
body->addCollider(collider);

float dt = 1.0f; // delta time
world.Step(dt); // Now the world will update!
```
### Add Constraint
```c++
world.addConstraint(new Link(object1, object2)); // Create a link between two objects
world.addConstraint(new ScreenBoarder()); // Create a universal constraint that runs on every object
```

## Explanation
### Body
Each body will contain a collider, which can be customizable. Each body will also contain a BodyData, which can store different variables for different shapes.
### Collider
Collider is also customizable, all you have to do to add a new collider is to define how it interacts with other colliders.
### Constraint
Constraint is also customizable, whether it is a constraint betwenn two, three or more bodies.
### Universal Constraint
Universal Constraint is also customizable. It runs on every object, which is suitable for something like a screen boarder. 
