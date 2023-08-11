workspace "OpenGLProject"
    configurations { "Debug", "Release" }
    platforms { "x64" }

project "OpenGLProject"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++11"

    targetdir ("bin/%{cfg.buildcfg}")
    objdir ("obj/%{cfg.buildcfg}")

    files { "main.cpp" }

    includedirs {
        "vendors/glfw/include",
        "vendors/glew/include"
    }

    links {
        "GLFW",
        "GLEW",
        "GL"
    }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

    filter "system:linux"
        links { "dl", "pthread", "X11", "Xrandr", "Xi", "Xxf86vm", "Xinerama", "Xcursor" }

    filter {}

group "Dependencies"
    include "vendors/glfw"
    include "vendors/glew"

