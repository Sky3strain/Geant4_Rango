#Python code to create a histogram of edep vs count data. 
import matplotlib.pyplot as plt
import numpy as np

#Import text file
dataBe1MM = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/Plots/TransmissionStudies/Transmission_1-10000keV_Be1MM.txt", delimiter=',', dtype=float)
dataMg1MM = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/Plots/TransmissionStudies/Transmission_1-10000keV_Mg1MM.txt", delimiter=',', dtype=float)
dataAl1MM = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/Plots/TransmissionStudies/Transmission_1-10000keV_Al1MM.txt", delimiter=',', dtype=float)
dataAl2MM = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/Plots/TransmissionStudies/Transmission_1-10000keV_Al2MM.txt", delimiter=',', dtype=float)
dataTef100MIC = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/Plots/TransmissionStudies/Transmission_1-10000keV_Tef0.1MM.txt", delimiter=',', dtype=float)
dataTef200MIC = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/Plots/TransmissionStudies/Transmission_1-10000keV_Tef0.2MM.txt", delimiter=',', dtype=float)


#plot
plt.plot(dataBe1MM[:,0], dataBe1MM[:,1], color='fuchsia', label="Be 1mm")
plt.plot(dataMg1MM[:,0], dataMg1MM[:,1], color='deepskyblue', label="Mg 1mm")
plt.plot(dataAl1MM[:,0], dataAl1MM[:,1], color='limegreen', label="Al 1mm")
plt.plot(dataAl2MM[:,0], dataAl2MM[:,1], color='black', label="Al 2mm")
plt.plot(dataTef100MIC[:,0], dataTef100MIC[:,1], color='coral', linestyle='--', label="Teflon 0.1mm")
plt.plot(dataTef200MIC[:,0], dataTef200MIC[:,1], color='purple', linestyle='--', label="Teflon 0.2mm")

plt.legend(fontsize=16)
plt.xscale("log")
plt.ylim(0,1.05)
plt.xticks(fontsize=16)
plt.yticks(fontsize=16)
plt.xlabel("Energy (keV)", fontsize=16)
plt.ylabel("Transmission", fontsize=16)
plt.title("Transmission Be(1mm), Mg(1mm), Al(1mm/2mm), and Teflon(0.1mm/0.2mm) 1-10000keV", fontsize=16)
plt.show()