---
theme: default
style: |
  section.lead h1 {
    font-size: 2.5rem;
    text-align: center;
    color: #6699FF;
  }
  section.lead h2 {
    font-size: 2.0rem;
    text-align: center;
    position: absolute;
    top: 2rem;
    left: 2rem;
    right: 2rem;
    color: #6699FF;
  }
    
paginate: false
class: 
    - lead
    - invert
marp: true
---
<style scoped>
h2 {
    text-align: center;
    position: unset;
    color: white;
}
</style>

# Introduction to ROS


---
<style scoped>
h3 {
    text-align: center;
    position: unset;
    color: white;
}
</style>

# What is ROS?

### Middleware framework for robot software development
### Facilitates communication between different robot components

---
<style scoped>
h3 {
    text-align: center;
    position: UNSET;
    color: white;
}
</style>
# Why Use ROS?

- Modularity and reusability
- Large, active community
- A lot of libraries and tools provided

### OPEN SOURCE FTW!!

---
<style scoped>
h3 {
    text-align: center;
    position: UNSET;
    color: white;
}
</style>
# What are ROS Nodes?

- Nodes are individual processes that handle specific tasks
- Examples:
  - Sensor node
  - Motor control node
  - Camera node
- Can be combined to create a complete robot system

---
<style scoped>
h3 {
    text-align: center;
    position: UNSET;
    color: white;
}
</style>
# Node Communication
### How do nodes **communicate**?

- **Publish/Subscribe mechanism**
- **Services**
- **Actions**

---


# ROS Messages

- ROS messages define the data exchanged between nodes
- Predefined message types (e.g., `sensor_msgs`, `geometry_msgs`)
- Example message:

```cpp
# geometry_msgs/Point
float64 x
float64 y
float64 z
