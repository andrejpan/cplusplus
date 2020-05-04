## build
```
mkdir build
cd build
cmake ..
make VERBOSE=1
```


## cmake-format
* `.cmake-format` is yaml configurational file. However VS Code plugin so far does not support *.yaml files.
* VS Code [plugin](https://marketplace.visualstudio.com/items?itemName=cheshirekow.cmake-format)

### system install
```
source ~/PATH_TO_VIRTUAL_ENV/bin/activate
pip install cmake-format
```

### Usage
* Activate `VIRTUAL_ENV` in the session and start VS Code from it.
* `CMakeLists.txt` files will be formatted on save.

## clang-format
* When `"editor.formatOnSave": true` the [plugin](https://marketplace.visualstudio.com/items?itemName=xaver.clang-format)
  will format cpp files on every save.

## clang-tidy
TODO enable it in `ccmake ..`, flags ENABLE_CLANG_TIDY and ENABLE_CPPCHECK
