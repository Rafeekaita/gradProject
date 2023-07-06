# Autonomous Self Driving Car Using Arduino UNO and Stepper Motors
## Abstract:
This thesis presents the design and implementation of an autonomous self-driving car using Arduino Uno and YOLO v4 for pedestrian detection. The vehicle is equipped with two stepper motors and motor drivers to control its movement. The aim of this project is to develop an inexpensive yet efficient self-driving car that can navigate a predefined path while avoiding collisions with pedestrians.

A dataset of over 25,000 images containing pedestrians in various environments was used to train the YOLO v4 object detection model. The trained model achieved a precision of 0.987, a recall of 0.985, and an F1-score of 0.986 on the test set.

The Arduino Uno microcontroller executes the trained YOLO v4 model to detect pedestrians in real-time and controls the stepper motors to steer the vehicle accordingly. The vehicle successfully navigated the predefined path in multiple trials while avoiding pedestrians, demonstrating the potential of deep learning models coupled with low-cost hardware for autonomous vehicle applications.

This research contributes to the growing body of literature on autonomous vehicle design and has the potential to provide inspiration for related projects. The promising results highlight the capabilities of deep learning for perceptual tasks in robotics when trained on large, high-quality datasets.



# Link To Dataset From Kaggle

- [Dataset](https://www.kaggle.com/datasets/karthika95/pedestrian-detection)
