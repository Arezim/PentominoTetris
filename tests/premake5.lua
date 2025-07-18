-- Copyright (c) 2020-2024 Jeffery Myers
--
--This software is provided "as-is", without any express or implied warranty. In no event 
--will the authors be held liable for any damages arising from the use of this software.

--Permission is granted to anyone to use this software for any purpose, including commercial 
--applications, and to alter it and redistribute it freely, subject to the following restrictions:

--  1. The origin of this software must not be misrepresented; you must not claim that you 
--  wrote the original software. If you use this software in a product, an acknowledgment 
--  in the product documentation would be appreciated but is not required.
--
--  2. Altered source versions must be plainly marked as such, and must not be misrepresented
--  as being the original software.
--
--  3. This notice may not be removed or altered from any source distribution.

baseName = path.getbasename(os.getcwd());

project (workspaceName .. "_Tests")
    kind "ConsoleApp"
    location "./"
    targetdir "../bin/Tests/"

    filter "action:vs*"
        debugdir "$(SolutionDir)"

    filter{}

    vpaths 
    {
        ["Header Files/*"] = { "include/**.h",  "include/**.hpp", "src/**.h", "src/**.hpp", "**.h", "**.hpp", "../game/include/**.h"},
        ["Source Files/*"] = {"src/**.c", "src/**.cpp","**.c", "**.cpp", "../game/src/pentomino.cpp"},
    }
    files {"**.c", "**.cpp", "**.h", "**.hpp"}
    
    files {"../game/src/pentomino.cpp"}

    includedirs { "./" }
    includedirs { "src" }
    includedirs { "include" }
    
    includedirs { "../game/include" }
    
    link_raylib()
    link_to("raygui")
