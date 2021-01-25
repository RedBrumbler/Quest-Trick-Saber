# Builds a .zip file for loading with BMBF
& $PSScriptRoot/build.ps1

if ($?) {
    Compress-Archive -Path "./libs/arm64-v8a/libTrickSaber.so","./libs/arm64-v8a/libbs-utils.so","./libs/arm64-v8a/libcodegen_0_6_1.so", "./libs/arm64-v8a/libbeatsaber-hook_1_0_10.so", "./libs/arm64-v8a/libcustom-types.so", "./bmbfmod.json" -DestinationPath "./TrickSaber_v0.3.0.zip" -Update
}
