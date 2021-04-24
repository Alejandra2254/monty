# what do i see
what do i see is an application made for detection of common objects based on a given image, when detecting the elements the application will output the name of the element and the times number  it finds the element in the image.

## How It Works

The backend of the application uses the cvlib library, (as long as the openCV, tensorflow packages are installed) after loading the image, the detection of objects is carried out with the call of the function detect_common_objects (). This returns Bbox (minimum bounding box), conf (confidence) and a label as a list of all the elements detected, which it uses to create a dictionary that has as a key the name of the element found and the value of the number of times it was found.

## Technologies used

* python3.5
* pip
* OpenCV
* Tensorflow

## Usage

