/*
 * Based on LTI Viewer Template 2009 by Pablo Alvarado
 * 
 *  Fabian Solano Madriz 2018
 */

#include <ltiViewer2D.h>
#include <ltiIOImage.h>
#include <ltiIOLTI.h>
#include <ltiImage.h>

#include <iostream>
#include <cstdlib>

void usage()  {
  std::cout <<
    "usage: ShowImage [options] \n\n"        \
    "       --img arg     Input image file\n" \
    "       --help        show this help\n"<< std::endl;    
}
int main(int argc,char* argv[]) {
  if(argc == 3 && std::string(argv[1])=="--img"){
    lti::ioImage loader;
    lti::image img;
    lti::channel8 chnl8;
    lti::channel chnl;
    lti::viewer2D::interaction action;
    lti::ipoint pos;
    
    bool loadOk=loader.load(argv[2],img);
	  chnl8.clear();
	  chnl.clear();
    if (loadOk) {
	
        // reading image successful
        static lti::viewer2D view;
        lti::viewer2D::parameters vpar(view.getParameters());
        vpar.title = argv[2]; // set the image name in the title bar
        view.setParameters(vpar);
        view.show(img); // show the image
        std::cout << "Enter any char to exit app." <<std::endl;
        getchar();
    }
    else{
      std::cout << "Error while loading the image file. Please try again"<<std::endl;
    }
  }
  else{
    std::cout << "Provide one image file to be displayed. \n"<< std::endl;
    usage();
    return EXIT_FAILURE;
  }
}