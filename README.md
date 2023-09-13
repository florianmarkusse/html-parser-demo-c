# HTML-PARSER-DEMO-C: A Demo Project for Using the html-parser in C!

## Overview

This is a demo project showcasing how to use the `html-parser` [library](https://github.com/florianmarkusse/html-parser) in a C project. The `html-parser` library allows you to parse HTML files in your C applications.

## Getting Started

Follow these steps to set up and run the demo project:

1. **Clone the Repository:**
    Clone this repository to your project folder using the following command:

    ```shell
    git clone https://github.com/florianmarkusse/html-parser-demo-c.git
    ```

2. **Install CMake:**
   Ensure that you have CMake installed on your system. If not, you can find installation instructions [here](https://cmake.org/install/).

3. **Download the `html-parser` Library:**
    Navigate to the `html-parser-demo-c` folder and create a `libs` directory. Then, clone the `html-parser` library in the new folder:

    ```shell
    mkdir libs
    cd libs
    git clone https://github.com/florianmarkusse/html-parser.git
    ```

4. **Build the `html-parser` Library:**

   Build the `html-parser` library based on your platform. Use the appropriate method below:

   - **For All Operating Systems:**
     ```shell
     cd html-parser
     cmake -S . -B build/ -D CMAKE_BUILD_TYPE="Release" -D BUILD_SHARED_LIBS="false" -D BUILD_TESTS="false" -D BUILD_BENCHMARKS="false"
     cmake --build build/
     ```

   - **For Linux or macOS:**
     If you are on Linux or macOS, you can use the provided `build.sh` script. Run the script with the `-h` flag to view all available build options:

     ```shell
     ./build.sh -h
     ```

5. **Build the Demo Project:**

   Build the demo project located in the `html-parser-demo-c` folder. Use the following commands based on your operating system:

   - **For All Operating Systems:**
     ```shell
     cd ..
     cmake -S . -B build/ -D CMAKE_BUILD_TYPE="Release"
     cmake --build build/
     ```

6. **Run the Demo Project:**

   Execute the demo project in the `html-parser-demo-c` folder with the following command:

   ```shell
   build/html-parser-demo-Release


## Feedback & Assistance
If you encounter any challenges or have suggestions related to the functionalities provided by this library, please do not hesitate to:
- [Open an issue](https://github.com/florianmarkusse/html-parser-demo-c/issues/new/choose), or;
- [Open a PR](https://github.com/florianmarkusse/html-parser-demo-c/compare).

## License
This project is licensed under the MIT License. See the [LICENSE](https://github.com/florianmarkusse/html-parser-demo-c/blob/main/LICENSE) file for details.
