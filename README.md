# Geant4_Rango - Rango Simulation

This is a Geant4-based simulation code developed for a Marshall Space Flight Center internship (Summer 2026)

## Overview

This project contains the Rango simulation code, a Geant4 application for testing the effective area of different scintillators and the transmission properties of different metals. 

## Prerequisites

- Geant4 installed and configured
- Root installed 

## Installation

1. Clone the repository
2. Create a file named build 
4. In build run Cmake ..
5. In build run make
6. Run ./Rango to initialize viewer and code
7. There is a macro file called Test.mac that uses a 662 keV gamma ray to use this do /control/execute Test.mac in the terminal
