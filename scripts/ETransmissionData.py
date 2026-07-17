#Python code to create a histogram of edep vs count data. 
import matplotlib.pyplot as plt
import numpy as np

#Import text file
dataBe1MM = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/scripts/DetCharacterization_txt/Transmission_1-10000keV_Be1MM.txt", delimiter=',', dtype=float)
dataMg1MM = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/scripts/DetCharacterization_txt/Transmission_1-10000keV_Mg1MM.txt", delimiter=',', dtype=float)
dataAl1MM = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/scripts/DetCharacterization_txt/Transmission_1-10000keV_Al1MM.txt", delimiter=',', dtype=float)
dataAl2MM = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/scripts/DetCharacterization_txt/Transmission_1-10000keV_Al2MM.txt", delimiter=',', dtype=float)
dataTef100MIC = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/scripts/DetCharacterization_txt/Transmission_1-10000keV_Tef0.1MM.txt", delimiter=',', dtype=float)
dataTef200MIC = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/scripts/DetCharacterization_txt/Transmission_1-10000keV_Tef0.2MM.txt", delimiter=',', dtype=float)

#plot
plt.plot(dataBe1MM[:,0], dataBe1MM[:,1], color='blue', label="Be 1mm", alpha=0.8)
plt.fill_between(dataTef100MIC[:,0], dataTef100MIC[:,1], dataTef200MIC[:,1], color='lightsalmon', alpha=0.5)
plt.plot(dataTef100MIC[:,0], dataTef100MIC[:,1], color='tomato', linestyle='--', label="Teflon 0.1mm", alpha=0.8)
plt.plot(dataTef200MIC[:,0], dataTef200MIC[:,1], color='red', linestyle='--', label="Teflon 0.2mm",alpha=0.8)
plt.plot(dataMg1MM[:,0], dataMg1MM[:,1], color='deeppink', label="Mg 1mm", alpha=0.8)
plt.plot(dataAl1MM[:,0], dataAl1MM[:,1], color='blueviolet', label="Al 1mm", alpha=0.8)
plt.plot(dataAl2MM[:,0], dataAl2MM[:,1], color='indigo', label="Al 2mm", alpha=0.8)


plt.legend(fontsize=16)
plt.xscale("log")
plt.ylim(0,1.0)
plt.xticks(fontsize=16)
plt.yticks(fontsize=16)
plt.xlabel("Energy (keV)", fontsize=16)
plt.ylabel("Transmission", fontsize=16)
plt.grid(which='major', axis='y', linestyle='-', alpha=0.5)
plt.axhline(y=0.1, color='gray', linestyle='-', linewidth=1,alpha=0.5)
plt.axhline(y=0.3, color='gray', linestyle='-', linewidth=1,alpha=0.5)
plt.axhline(y=0.5, color='gray', linestyle='-', linewidth=1,alpha=0.5)
plt.axhline(y=0.7, color='gray', linestyle='-', linewidth=1,alpha=0.5)
plt.axhline(y=0.9, color='gray', linestyle='-', linewidth=1,alpha=0.5)
plt.title("Gamma Ray Transmission For Different Materials Capped At 1.0", fontsize=16)
plt.tight_layout()
plt.show()