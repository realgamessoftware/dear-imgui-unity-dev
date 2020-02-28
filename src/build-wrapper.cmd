@echo off
setlocal

set "input_origin_folder=cimgui\generator\output"
set "generator_folder=imgui.net\src\CodeGenerator"
set "generator_input=(definitions.json struct_and_enums.json)"
set "output_destination=..\dear-imgui-project\Packages\imgui\ImGuiNET\Wrapper\Generated"

for %%i in %generator_input% do copy %input_origin_folder%\%%i %generator_folder% >NUL

dotnet run --project %generator_folder% -- %output_destination%
