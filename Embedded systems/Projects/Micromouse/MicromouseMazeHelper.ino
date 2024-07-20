// // Function to optimize the path
// String optimizePath(String path) {
//     Serial.println("Optimizing the path.");
//     path.replace("LBL", "S");
//     path.replace("LBS", "R");
//     path.replace("RBL", "B");
//     path.replace("SBS", "B");
//     path.replace("SBL", "R");
//     path.replace("LBR", "B");
//     return path;
// }

// // Function to move the car
// void moveCar() {
//     sensor_position = traceSensors(); // Get sensor data
//     processSensorData(sensor_position); // Process sensor data

//     bool left_IR = digitalRead(IR_SENSOR_LEFT); // Read left IR sensor
//     bool right_IR = digitalRead(IR_SENSOR_RIGHT); // Read right IR sensor
//     bool middle_sensor = digitalRead(MIDDLE_IR_PIN) == LOW; // Read middle sensor
//     bool left_sensor = digitalRead(FAR_LEFT_IR_PIN) == LOW; // Read left far sensor
//     bool right_sensor = digitalRead(RIGHT_IR_PIN) == LOW; // Read right near sensor
//     bool rear_right_IR = digitalRead(IR_SENSOR_RIGHT_REAR); // Read right rear IR sensor
//     bool left_near_sensor = digitalRead(LEFT_IR_PIN) == LOW; // Read left near sensor

//     // Check if the car reached the end
//     if (sensor_position == B11111 && left_IR && right_IR && rear_right_IR) {
//         end_counter++;
//     } else {
//         end_counter = 0;
//         // If the left IR sensor or left near sensor detects the line
//         if (left_IR || left_near_sensor) {
//             controlSpeed(0, 0); // Stop the car
//             delay(500);
//             rotateLeft(); // Rotate left
//             if (path[path.length() - 1] != 'L') {
//                 path += "L";
//                 path = optimizePath(path);
//             }
//             controlSpeed(0, 0); // Stop after rotation
//             delay(rotation_delay);
//         } 
//         // If the right IR sensor detects the line and no sensors are active
//         else if (right_IR && sensor_position == B00000) {
//             controlSpeed(0, 0); // Stop the car
//             delay(500);
//             controlSpeed(rotation_speed - 20, 0); // Start rotation
//             delay(400);
//             controlSpeed(0, 0); // Stop after rotation
//             if (sensor_position == B00000) {
//                 rotateRight(); // Rotate right
//                 if (path[path.length() - 1] != 'R') {
//                     path += "R";
//                     path = optimizePath(path);
//                 }
//                 controlSpeed(0, 0); // Stop after rotation
//                 delay(rotation_delay);
//             }
//         }

//         // If no sensors are active
//         if (sensor_position == B00000 && !left_IR && !rear_right_IR) {
//             counter180++;
//         } else {
//             counter180 = 0;
//         }
//         // If the car has been off the line for a while
//         if (counter180 == 65) {
//             if (sensor_position == B00000) {
//                 controlSpeed(0, 0); // Stop the car
//                 delay(500);
//                 current_time = millis();
//                 bool went_back = rotate180(); // Rotate 180 degrees
//                 controlSpeed(0, 0); // Stop after rotation
//                 previous_time = millis() - current_time;
//                 current_time = millis();
//                 while (sensor_position != B00000) {
//                     sensor_position = traceSensors();
//                     controlSpeed(0, rotation_speed - 20); // Rotate to find the line
//                 }
//                 rotate180(true); // Rotate 180 degrees again
//                 controlSpeed(0, 0); // Stop after rotation
//                 current_time = millis() - current_time;
//                 if (path[path.length() - 1] != 'B') {
//                     path += "B";
//                     path = optimizePath(path);
//                 }

//                 if (current_time < previous_time) {
//                     rotate180(); // Rotate 180 degrees again
//                 }
//             }
//             counter180 = 0;
//         }
//     }
// }

// // Function to replay the path
// void replayPath() {
//     sensor_position = traceSensors(); // Get sensor data
//     processSensorData(sensor_position); // Process sensor data

//     bool left_IR = digitalRead(IR_SENSOR_LEFT); // Read left IR sensor
//     bool right_IR = digitalRead(IR_SENSOR_RIGHT); // Read right IR sensor
//     bool middle_sensor = digitalRead(MIDDLE_IR_PIN) == LOW; // Read middle sensor
//     bool left_sensor = digitalRead(FAR_LEFT_IR_PIN) == LOW; // Read left far sensor
//     bool right_sensor = digitalRead(RIGHT_IR_PIN) == LOW; // Read right near sensor
//     bool rear_right_IR = digitalRead(IR_SENSOR_RIGHT_REAR); // Read right rear IR sensor
//     bool left_near_sensor = digitalRead(LEFT_IR_PIN) == LOW; // Read left near sensor

//     // Replay the path based on stored commands
//     if (path[i] == 'L' && (left_IR || left_near_sensor)) {
//         controlSpeed(0, 0); // Stop the car
//         delay(500);
//         rotateLeft(); // Rotate left
//         controlSpeed(0, 0); // Stop after rotation
//         delay(rotation_delay);
//         i++;
//     } else if (path[i] == 'R' && right_IR) {
//         controlSpeed(0, 0); // Stop the car
//         delay(500);
//         rotateRight(); // Rotate right
//         controlSpeed(0, 0); // Stop after rotation
//         delay(rotation_delay);
//         i++;
//     }
// }

// // Function to trace sensor readings
// long traceSensors() {
//     long sensor_readings = B00000;
//     long sensor_array[5] = {
//         !digitalRead(FAR_RIGHT_IR_PIN),
//         !digitalRead(RIGHT_IR_PIN),
//         !digitalRead(MIDDLE_IR_PIN),
//         !digitalRead(FAR_LEFT_IR_PIN),
//         !digitalRead(LEFT_IR_PIN)
//     };

//     // Update sensor readings based on array
//     for (long i = 0; i < 5; i++) {
//         if (sensor_array[i] == HIGH) {
//             sensor_readings += (0x1 << i);
//         }
//     }

//     return sensor_readings;
// }

// // Main loop function
// void loop() {
//     delay(5); // Short delay for stability
//     moveCar(); // Move the car based on sensor readings
// }
