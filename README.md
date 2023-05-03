
# AI Motion Detection


This is a simple motion detection program that uses OpenCV to detect motion in a video stream in real-time.


# How it Works:
The program captures video frames from a network camera or video file and processes them in real-time to detect motion using a simple algorithm:
1. Convert each frame to grayscale and apply a Gaussian blur to remove noise.  

2. Subtract the first frame from the current frame to get a "delta" frame that highlights areas of motion


3. Threshold the delta frame to get a binary image that highlights the areas of motion.

4. Apply morphological operations (dilation) to remove noise and fill in small gaps in the binary image.

5. Find contours in the binary image and draw bounding rectangles around them on the original color frame.

6. Display the processed frame with bounding rectangles drawn on it in a window.
 



# Requirements:
Before you can run this AI Motion Detection locally, you need to have the following software installed on your system:

- OpenCV 4.5 or later.
- C++ compiler (GCC or Clang).
- Git.  



# How to Run :
To run the AI Motion Detection , follow these steps:

1. Clone or fork the repository:
```bash
git clone https://github.com/AGS2023/AI-Motion-Detection.git

```
\
2. Navigate to the cloned repository:
```bash
cd AI-Motion-Detection

```
\
3. Install OpenCV on your system if you haven't already.

\
4. Compile the program using the following command:
```bash
g++ -o ai_motion ai_motion.cpp `pkg-config --cflags --libs opencv`\

```

or :
```bash
clang++ -o ai_motion ai_motion.cpp `pkg-config --cflags --libs opencv`

```
5. Run the program using the following command:
```bash
./ai_motion

```
# Notes
- This program assumes that the network camera is streaming video over an HTTP protocol at the specified IP address and port, and the camera supports the MJPEG format.
- The program uses the ` findContours() ` function to detect motion. You may need to adjust the threshold value and contourArea threshold in the code to get better results, depending on your specific use case.




