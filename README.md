# VLSI Project: 3D Rendering

The host files (test bench) are in the host folder. Include the 3 .cpp files as test bench files, while also defining the MACRO HW using **-DHW** for both C-sim and Co-sim.

The correponding area/latency/base solutions are in their respective folders. Include the .cpp file as main file, selecting *rendering* as top function.

While running C sim or Co-sim, pass in the input argument to the reference file as (included in this directory, required for testing):
```
-f <absolute path to outputs file>
```
Make sure to use linux style folder separators (/)

E.x:
```
-f C:/Users/Arpit/Desktop/3d_base/outputs_golden.txt
```
