d3d8to9
=======

[![Build Status](https://ci.appveyor.com/api/projects/status/aqupdda60ixgenyd?svg=true)](https://ci.appveyor.com/project/crosire/d3d8to9)

This is a pseudo-driver module that intends to improve compatibility and stability in games using Direct3D 8 for rendering by converting all API calls and low-level shaders to equivalent Direct3D 9 ones. By that it also opens those games to new possibilities from proven modding tools written for Direct3D 9, including [ReShade](http://reshade.me).

Note that d3d8to9 does exact translation from Direct3D 8 to Direct3D 9 only. But on recent versions of Windows, depending on system settings, GPU drivers and other factors, rendering behavior in Direct3D 9 using d3d8to9 may differ from native Direct3D 8. One common issue is VSync getting enabled with d3d8to9, even though it appears inactive in native Direct3D 8, despite the application enabling it. This may give an inaccurate impression of lower performance with d3d8to9, while it actually follows what the application requests. If you want to tweak this behavior, such as forcing VSync to be off, it is recommended to use a separate tool, such as [dxwrapper](https://github.com/elishacloud/dxwrapper), which uses d3d8to9 internally for API call conversion, but adds additional configuration opportunities.

## Building

You'll need Visual Studio 2013 or higher to build d3d8to9. It is recommended to install the old standalone DirectX end-user runtime, which is required for the D3DX libraries used for disassembling and assembling the shaders.

A quick overview of what some of the source code files contain:

|File                                                      |Description                                                                      |
|----------------------------------------------------------|---------------------------------------------------------------------------------|
|[d3d8to9.cpp](source/d3d8to9.cpp)                         | Definition of the main D3D8 entry point `Direct3DCreate8`                       |
|[d3d8to9_base.cpp](source/d3d8to9_base.cpp)               | Implementation of the `IDirect3D8` interface, including device creation         |
|[d3d8to9_device.cpp](source/d3d8to9_device.cpp)           | Implementation of the `IDirect3DDevice8` interface, including shader conversion |
|[d3d8types.hpp](source/d3d8types.hpp)                     | Declaration of all used D3D8 types one would otherwise find in d3d8.h           |
|[interface_query.hpp](source/interface_query.hpp)         | Table to map D3D9 interface addresses to their matching D3D8 implementations    |

## Contributing

Any contributions to the project are welcomed, it's recommended to use GitHub [pull requests](https://help.github.com/articles/using-pull-requests/).

A big shout-out to all the existing [contributors](https://github.com/crosire/d3d8to9/graphs/contributors) who worked on improving compatibility, especially [elishacloud](https://github.com/elishacloud)!

## License

All source code in this repository is licensed under a [BSD 2-clause license](LICENSE.md).
