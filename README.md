# Walking-Robot-V1
Specifications about the first design of the walking robot
- Includes technical specs such as servo types & connections between the batteries, regulator, servo driver, and ESP board
- Includes actuation drawings for the robot legs
- Using ROS on the computer side to use a joystick and turn it into a command velocity
- The cmd_vel is then turned into a number like "5050" which means no walk and no turn.
- The first number in the messages signifies the walk speed, which is calculated as a value from 1 to -1, and is the substring of the first 2 numbers, -50, then divided by 40.
- The second number is the same, as 90 is full right and 10 is full left
- Running 3 nodes: joy node, joy teleop node, and wsjs node
- Using a telnet connection on the gateway 192.168.1.1
- Running on access point mode, to run the launch file you need to setup the IPV4 addresses and connect to the ESP
