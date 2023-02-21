# 📈 Visualization Of Automatic Control Signals: Reading the Angular Position

> ☣ **Warning:** This project was created for educational purposes only. It may contain non-optimal or outdated solutions. 

> ☢ **Warning:** Comments in the code are in Polish

### 📜 About
Implemented program for loading, processing and visualizing data of the current **angular position (roll, pitch, yaw)** of the mobile robot. In addition to drawing a *chart* of the position from time to time, the program draws a simple *compass* and displays the current direction of the robot (at the beginning of the movement the robot was facing north). It is also possible to select a data file, reject the interrupted *n* samples, and choose what the OY axis should represent. Project was implemented in Visual Studio 2019 using Windows Forms (CRL Project with. Net Framework 4.7.2).

<img src="/_readmeImg/Screen0.png?raw=true 'Main window'" width="500">

### 🎯 How to run?
To run the program and ensure its correct operation, you should:
1. Make sure that Visual Studio 2019 has **C++/CLI support for v142 build tools** installed.
	Help: https://docs.microsoft.com/en-us/cpp/dotnet/dotnet-programming-with-cpp-cli-visual-cpp?view=msvc-160
2. Go to *Project->Project3WSA Properties->Configuration Properties->Linker->System* and change the value of *SubSystem* to **Windows (/SUBSYSTEM: WINDOWS)**.

<img src="/_readmeImg/Screen1.png?raw=true 'Settings I'" width="500">

3. Go to *Project->Project3WSA Properties->Configuration Properties->Linker->Advanced* and change the value of *Entry point* to **main**.

<img src="/_readmeImg/Screen2.png?raw=true 'Settings II'" width="500">

4. If errors appear at startup, try to enter the folder with the project, open the settings file of file *FormWSA.resx* and select **Unblock** (if there is such an option).

*Additionally:* if you see an error when you first open the project instead of the form, you must restart Visual Studio.

### 💻 How does it work?
Windows Forms is a pretty nice tool for doing GUI. We have a lot of different settings for window elements, which we do not necessarily have to manually enter into the code. The operation of this program can be determined in several steps:
- Start - display window elements, draw a compass without an arrow.
- The user selects various options and presses **Naszkocowac i pokazac kompas**.
- Program processes the selected options.
- Program loads 1 line from the file and adds a point to the graph. The compass needle changes its direction. All this repeats every 1/25 second (imitation that the sensor gives data at a frequency of 25 Hz).
- When the file is fully read, the appropriate message will be displayed and you can start visualizing again, for example, data from another file.

Keep in mind the unusual coordinate system of the form, pictureboxes and other elements.

<img src="/_readmeImg/Image_PB.png?raw=true 'PB'" width="500">

It is also worth noting that only the position **Yaw** affects the position of the compass arrow (see picture below).

<img src="/_readmeImg/Image_RPY.jpg?raw=true 'PB'" width="500">

### 💪 Authors
- **Tomash Mikulevich** 
- **Igor Malkovskiy**
