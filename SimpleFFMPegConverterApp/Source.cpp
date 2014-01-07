#include "stdafx.h"


bool find_file( const std::string & file_ext, // search for this extension
                std::vector<boost::filesystem::path> & filePathsToConvert );            // files paths to convert

int main()
{
	std::string fileExtension(".avi");

	std::cout << "hello" << std::endl;
	std::vector<boost::filesystem::path> filePathsToConvert;
	std::cout << "Current path of executable is " + boost::filesystem::current_path().string() << std::endl;
	

	std::cout << "Iterating over files in directory..." << std::endl;
	find_file(fileExtension, filePathsToConvert);

	std::cout << "Iteration complete. Number of matching files: " << filePathsToConvert.size() << ". Listing files matching " << fileExtension << std::endl;

	for (boost::filesystem::path mypath : filePathsToConvert)
		std::cout << mypath.string() << std::endl;

	std::cout << "Writing batch file with FFMPEG commands..." << std::endl;
	std::ofstream myfile;
	myfile.open ("convert_avi_to_mp4.bat", std::ios::trunc);

	for (boost::filesystem::path mypath : filePathsToConvert)
		myfile << "ffmpeg -i " <<  mypath.stem() << ".avi -acodec copy -vcodec copy " << mypath.stem() << ".mp4 " << std::endl;

	myfile.close();
	std::cout << "Running batch file..." << std::endl;

	system("convert_avi_to_mp4.bat");

	

	std::cout << "Conversion complete. Press enter to close window. " << std::endl;

	std::cin.get();
}

//bool find_file( const boost::filesystem::path & dir_path,         // in this directory,
 //               const std::string & file_name, // search for this name,
  //              boost::filesystem::path & path_found )            // placing path here if found



bool find_file( const std::string & file_ext, // search for this extension
                std::vector<boost::filesystem::path> & filePathsToConvert )            // files paths to convert
{
  bool foundAtLeastOne = false;
  boost::filesystem::directory_iterator end_itr; // default construction yields past-the-end
  for ( boost::filesystem::directory_iterator itr( boost::filesystem::current_path() );
        itr != end_itr;
        ++itr )
  {
	  if(!boost::filesystem::is_directory(itr->path()))
	  {
		  if ( itr->path().extension().compare(file_ext) == 0)
		  {
			  //extension matches, push path onto vector
			  filePathsToConvert.push_back( itr->path() );
			  foundAtLeastOne = true;
		  }
	  }


  }
  return foundAtLeastOne;
}
