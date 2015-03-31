d3d8to9
=======

"d3d8to9" is a pseudo-driver module that intends to improve compatibility and stability in games using Direct3D8 for rendering by converting all API calls and lowlevel shaders to equivalent Direct3D9 ones. By that it also opens those games to new possibilities proven tools and wrappers for Direct3D9 can provide.

This project is part of [ReShade](http://reshade.me), an advanced and generic post-processing injector, but now maintained as an open source standalone too, in the hope for it being useful to the community and to improve it together.

## Contributing

You'll need Visual Studio 2012 or higher to open the project file (this however is no requirement) and the standalone DirectX SDK, required for the D3DX headers and libraries used for disassembling and assembling the shaders.

Any contributions to the project are welcomed, it's recommended to use GitHub [pull requests](https://help.github.com/articles/using-pull-requests/).

## License

All the source code is licensed under the conditions of the [zlib license](LICENSE.txt).
