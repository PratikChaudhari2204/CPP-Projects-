#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void displayImage(const Mat &image) {
    imshow("Processed Image", image);
    waitKey(0);
}

Mat convertToGrayscale(const Mat &image) {
    Mat grayImage;
    cvtColor(image, grayImage, COLOR_BGR2GRAY);
    return grayImage;
}

Mat applyBlur(const Mat &image) {
    Mat blurredImage;
    GaussianBlur(image, blurredImage, Size(15, 15), 0);
    return blurredImage;
}

Mat applySharpen(const Mat &image) {
    Mat sharpenedImage;
    Mat kernel = (Mat_<float>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    filter2D(image, sharpenedImage, image.depth(), kernel);
    return sharpenedImage;
}

Mat adjustBrightnessAndContrast(const Mat &image, double alpha, int beta) {
    Mat adjustedImage;
    image.convertTo(adjustedImage, -1, alpha, beta);
    return adjustedImage;
}

Mat resizeImage(const Mat &image, int newWidth, int newHeight) {
    Mat resizedImage;
    resize(image, resizedImage, Size(newWidth, newHeight));
    return resizedImage;
}

Mat cropImage(const Mat &image, int x, int y, int width, int height) {
    Rect roi(x, y, width, height);
    return image(roi);
}

void saveImage(const Mat &image, const string &filePath) {
    imwrite(filePath, image);
    cout << "Image saved as " << filePath << endl;
}

int main() {
    string imagePath;
    cout << "Enter the image path: ";
    cin >> imagePath;

    Mat image = imread(imagePath);
    if (image.empty()) {
        cout << "Could not open or find the image!" << endl;
        return -1;
    }

    int choice;
    do {
        cout << "\nImage Processing Tool\n";
        cout << "1. View Image\n";
        cout << "2. Convert to Grayscale\n";
        cout << "3. Apply Blur\n";
        cout << "4. Apply Sharpen\n";
        cout << "5. Adjust Brightness and Contrast\n";
        cout << "6. Resize Image\n";
        cout << "7. Crop Image\n";
        cout << "8. Save Image\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            displayImage(image);
        }
        else if (choice == 2) {
            image = convertToGrayscale(image);
            displayImage(image);
        }
        else if (choice == 3) {
            image = applyBlur(image);
            displayImage(image);
        }
        else if (choice == 4) {
            image = applySharpen(image);
            displayImage(image);
        }
        else if (choice == 5) {
            double alpha;
            int beta;
            cout << "Enter contrast factor (alpha): ";
            cin >> alpha;
            cout << "Enter brightness factor (beta): ";
            cin >> beta;
            image = adjustBrightnessAndContrast(image, alpha, beta);
            displayImage(image);
        }
        else if (choice == 6) {
            int newWidth, newHeight;
            cout << "Enter new width: ";
            cin >> newWidth;
            cout << "Enter new height: ";
            cin >> newHeight;
            image = resizeImage(image, newWidth, newHeight);
            displayImage(image);
        }
        else if (choice == 7) {
            int x, y, width, height;
            cout << "Enter the x and y coordinates for top-left corner: ";
            cin >> x >> y;
            cout << "Enter width and height for cropping: ";
            cin >> width >> height;
            image = cropImage(image, x, y, width, height);
            displayImage(image);
        }
        else if (choice == 8) {
            string savePath;
            cout << "Enter the file path to save the image: ";
            cin >> savePath;
            saveImage(image, savePath);
        }
        else if (choice == 9) {
            cout << "Exiting program...\n";
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 9);

    return 0;
}
