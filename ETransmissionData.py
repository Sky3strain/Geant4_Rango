#Python code to create a histogram of edep vs count data. 
import matplotlib.pyplot as plt
import numpy as np

#Import text file
dataBe1MM = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/Plots/TransmissionStudies/Transmission_1-10000keV_Be1MM.txt", delimiter=',', dtype=float)
dataMg1MM = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/Plots/TransmissionStudies/Transmission_1-10000keV_Mg1MM.txt", delimiter=',', dtype=float)
dataAl1MM = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/Plots/TransmissionStudies/Transmission_1-10000keV_Al1MM.txt", delimiter=',', dtype=float)
dataTef100MIC = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/Plots/TransmissionStudies/Transmission_1-10000keV_Tef0.1MM.txt", delimiter=',', dtype=float)
dataTef200MIC = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/Plots/TransmissionStudies/Transmission_1-10000keV_Tef0.2MM.txt", delimiter=',', dtype=float)


#plot
plt.plot(dataBe1MM[:,0], dataBe1MM[:,1], color='fuchsia', label="Be 1mm")
plt.plot(dataMg1MM[:,0], dataMg1MM[:,1], color='deepskyblue', label="Mg 1mm")
plt.plot(dataAl1MM[:,0], dataAl1MM[:,1], color='limegreen', label="Al 1mm")
plt.plot(dataTef100MIC[:,0], dataTef100MIC[:,1], color='coral', linestyle='--', label="Teflon 0.1mm")
plt.plot(dataTef200MIC[:,0], dataTef200MIC[:,1], color='purple', linestyle='--', label="Teflon 0.2mm")

plt.legend(fontsize=14)
plt.xscale("log")
plt.ylim(0,1.05)
plt.xticks(fontsize=14)
plt.yticks(fontsize=14)
plt.xlabel("Energy (keV)", fontsize=14)
plt.ylabel("Transmission", fontsize=14)
plt.title("Transmission Be(1mm), Mg(1mm), Al(1mm), and Teflon(0.1mm/0.2mm) 1-10000keV", fontsize=14)
plt.show()

#Template to do transmission calculations in python
# resultsTef200MIC = []
# j = 1
# for j in range(1, 31):
#     data_chunck_Tef2 = []
#     for col1, col2 in dataTef200MIC:
#         if col1 == j:
#             data_chunck_Tef2.append(col2)
#     array_chunck = np.array(data_chunck_Tef2)
#     counter = data_chunck_Tef2.count(2)
#     ones = data_chunck_Tef2.count(1)
#     transmission = counter/(counter+ones)
#     resultsTef200MIC.append((j, transmission))
# result_array_Tef200MIC = np.array(resultsTef200MIC)
# print("Printing results of Teflon 200 --------------------------")
# print(result_array_Tef200MIC)
# print("---------------------------------------------------------")