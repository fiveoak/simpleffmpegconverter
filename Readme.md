## Simple FFmpeg Converter App

# Background

I made this quickly to mass convert some .avi files to .mp4, and to try out using boost libraries for the first time. It's pretty bad since it doesn't even actually link to the FFmmpeg libraries, it just does it in a really convoluted way by writing a .bat file with appropriate ffmpeg switches and then the user runs that. But in the future I might actually fix this to properly link to the FFmpeg libraries and support customized file extensions. I think using FFmpeg is a bit difficult for beginners, but very powerful - so a really simple, lightweight program to convert some things without spyware/ads would be nice.


# Usage

1. Put all video files in the same directory as the program (and ffmpeg.exe, if ffmpeg.exe isn't in the user's path environment variable)
2. Run the program to generate a .bat file
3. Run .bat file to convert files
