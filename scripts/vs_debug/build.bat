set PRO_ROOT=%~dp0/../..
set BUILD_TYPE=Debug

conan install %PRO_ROOT%^
    --profile %~dp0/conan_debug_profile^
    --build=missing

cmake -G "Visual Studio 16 2019"^
    -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake^
    -DCMAKE_BUILD_TYPE=%BUILD_TYPE%^
    -DCMAKE_WINDOWS_EXPORT_ALL_SYMBOLS=TRUE^
    -DBUILD_SHARED_LIBS=TRUE^
    %PRO_ROOT%

cmake --build .
cmake --install . --config %BUILD_TYPE%
