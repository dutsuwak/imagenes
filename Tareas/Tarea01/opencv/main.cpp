#include <boost/program_options.hpp>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <iterator>

using namespace cv;
namespace po = boost::program_options;

int main(int ac, char* av[]){
    try {
        po::options_description desc("Allowed options");
        desc.add_options()
            ("help", "Generate help message")
            ("img", po::value<string>(), "set path to image file")
        ;

        po::variables_map vm;        
        po::store(po::parse_command_line(ac, av, desc), vm);
        po::notify(vm);    

        if (vm.count("help")) {
            std::cout << desc << "\n";
            return 0;
        }

        if (vm.count("img")) {
            std::cout << "Image path set to: " << vm["img"].as<string>() << ".\n";
            
            /** OPENCV CODE **/
            Mat image;
            image = imread( vm["img"].as<string>(), 1 );

            if ( !image.data ){
                printf("No image data \n");
                return -1;
            }
            
            namedWindow("Display Image", WINDOW_AUTOSIZE );
            imshow("Display Image", image);
            waitKey(0);

            return 0;
        } 
        else {
            std::cout << "Image path was not set.\nPlease run program with --help option for more details.\n";
        }
    }
    catch(std::exception& e) {
        std::cerr << "error: " << e.what() << "\n";
        return 1;
    }
    catch(...) {
        std::cerr << "Exception of unknown type!\n";
    }

    return 0;
}