This is an exact copy of the original IGodsEye repository this is not updated nor will I update it for you.

I HAD TO MAKE A FORK OF MY FORK BECAUSE GITHUB IS A JEWISH WEBSITE 
If you are having issues compiling here are the project properties

1. General -> Platform Toolset -> v142
2. Advanced -> Use of MFC -> Use MFC in a Static Library
3. Advanced -> Character Set -> Use Unicode Character Set
4. C/C++ -> General -> Additional Include Directories = $(ProjectDir);vendors/minhook/include;%(AdditionalIncludeDirectories)
5. C/C++ -> Linker -> General -> Additional Library Directories = vendors/minhook/lib;%(AdditionalLibraryDirectories)
6. C/C++ -> Linker -> Input -> Additional Dependencies = d3d12.lib;dxgi.lib;libMinHook-x64-v142-md.lib;%(AdditionalDependencies)

Note: if you want to compile for a different platform toolset, you'll need to compile Minhook libraries for the toolset, include the .lib files in /vendors/minhook/lib and then change the Linker Input Additional Dependencies to the lib file for your toolset.

I was only able to complie it in debug x64 mode.
