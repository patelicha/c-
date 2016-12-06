getRectSubPix
blur
resize
findContours
mat


#include <iostream>


int main () 
{
	using namespacestd ;
	int a=0 ;

	cout<< "what effect do you want to apply to the image \n"<<
		<< " 1- crop and resize \n" <<	
		<< " 2- crop and resize \n" <<	
		<< " 3- crop and resize \n" <<	
		<< " 4- crop and resize \n" <<endl ;
	cin>>a ;
	

	switch (a)
	 {
		case 1:  // crop and resize
			{
				Mat image;
    				image = imread(argv[1], CV_LOAD_IMAGE_COLOR);
				
				int width , height ;
				
				cout<< " Enter the number of columns and rows " <<endl ;
				cin>>width>>height ;
				
				Size patchSize (width , height);
				
				cout<< " Enter the number of columns and rows " <<endl ; 
				cin>>width>>height ;
				
				Size dsize (width , height);
				
				cout<< " Enter the number of columns and rows " <<endl ;
				cin>>width>>height ;
				
				Size ksize (width , height);
			

				getRectSubPix(InputArray image, Size patchSize, Point2f center,OutputArray patch, int patchType=-1 ) ;   //extract  part
				
				resize(InputArray patch, OutputArray dst, Size dsize, double fx=0,double fy=0, int interpolation=INTER_LINEAR ) ; // resize the extracted rect
				blur(InputArray dst, OutputArray final, Size ksize, Pointanchor=Point(-1,-1),int borderType=BOR	DER_DEFAULT ) ;// smoothen the new image
	
				/// Create Window
  				char* source_window = "Source";
  				namedWindow( source_window, CV_WINDOW_AUTOSIZE );
  				imshow( source_window, image );

				/// Show in a window
 				namedWindow( "Resized", CV_WINDOW_AUTOSIZE );
  				imshow( "Resized", final );
				break ;
			} 


		case 2: //filter
  			{	
				Mat image;
    				image = imread(argv[1], CV_LOAD_IMAGE_COLOR);
				
				cout<< «Enter the number of columns and rows » <<endl ;
				cin>>width>>height ;
				
				Size ksize (width , height);
				
				double maxValue , c  ;
				int adaptiveMethod , thresholdType , blockSize ;
				
				cout<<" " <<endl ;   //enter the parameteres of the editing
 				cin>>maxValue>>adaptiveMethod ; //input them
				cin>>thresholdType>>blockSize>>c ;    //input them

				blur(InputArray image, OutputArray dst, Size ksize, Point anchor=Point(-1,-1), int borderType=BORDER_DEFAULT ) ;

				adaptiveThreshold(InputArray src, OutputArray dst, double maxValue, int adaptiveMethod, int thresholdType, int blockSize, double C) ;
 			 	
				/// Create Window
  				char* source_window = "Source";
  				namedWindow( source_window, CV_WINDOW_AUTOSIZE );
  				imshow( source_window, image );

				/// Show in a window
 				namedWindow( "filtered", CV_WINDOW_AUTOSIZE );
  				imshow( "filtered", dst );

				break;
			}





		case 3:
			{
				Mat canny_output;
  				vector<vector<Point> > contours;
 				vector<Vec4i> hierarchy;
				
				/// Load source image and convert it to gray
  				src = imread( argv[1], 1 );

  				/// Convert image to gray and blur it
  				cvtColor( src, src_gray, CV_BGR2GRAY );
  				blur( src_gray, src_gray, Size(3,3) );

  				/// Create Window
  				char* source_window = "Source";
  				namedWindow( source_window, CV_WINDOW_AUTOSIZE );
  				imshow( source_window, src );

  				createTrackbar( " Canny thresh:", "Source", &thresh, max_thresh, 				thresh_callback );
  				thresh_callback( 0, 0 );

  				void thresh_callback(int, void* )
					{
  						Mat canny_output;
  						vector<vector<Point> > contours;
  						vector<Vec4i> hierarchy;

 			 			/// Detect edges using canny
  						Canny( src_gray, canny_output, thresh, thresh*2, 3 );
  	
						/// Find contours
  						findContours(canny_output, contours, hierarchy, 										CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

  						/// Draw contours
  						Mat drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
  						for( int i = 0; i< contours.size(); i++ )
    			 			{
       						Scalar color = Scalar( rng.uniform(0, 255), 													rng.uniform(0,255),rng.uniform(0,255));
       						drawContours(drawing,contours,i,color, 2, 8, 														hierarchy, 0, Point() );
     						}

  				/// Show in a window
 				namedWindow( "Contours", CV_WINDOW_AUTOSIZE );
  				imshow( "Contours", drawing );
					}


  		
 	 			break;
			}

		case 4:
  		
 	 	break;

		default:	//Code to execute if <variable> does not equal the value 							//following any of the cases
	  	break;
}
