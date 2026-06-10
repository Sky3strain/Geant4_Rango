#Python code to create a histogram of edep vs count data. 
import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns
import pandas as pd

#Import text file
dataBe1MM = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/Plots/TransmissionStudies/Be1MM.txt", delimiter=',', dtype=int)
dataMg1MM = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/Plots/TransmissionStudies/Mg1MM.txt", delimiter=',', dtype=int)
dataAl1MM = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/Plots/TransmissionStudies/Al1MM.txt", delimiter=',', dtype=int)
dataTef100MIC = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/Plots/TransmissionStudies/Tef100MIC.txt", delimiter=',', dtype=int)
dataTef200MIC = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/Plots/TransmissionStudies/Tef200MIC.txt", delimiter=',', dtype=int)

resultsBe1MM = []
j = 1
for j in range(1, 31):
    data_chunck_Be = []
    for col1, col2 in dataBe1MM:
        if col1 == j:
            data_chunck_Be.append(col2)
    array_chunck = np.array(data_chunck_Be)
    counter = data_chunck_Be.count(2)
    ones = data_chunck_Be.count(1)
    transmission = counter/(counter+ones)
    resultsBe1MM.append((j, transmission))
result_array_Be1MM = np.array(resultsBe1MM)
print("Printing results of Be ----------------------------------")
print(result_array_Be1MM)
print("---------------------------------------------------------")

resultsMg1MM = []
j = 1
for j in range(1, 31):
    data_chunck_Mg = []
    for col1, col2 in dataMg1MM:
        if col1 == j:
            data_chunck_Mg.append(col2)
    array_chunck = np.array(data_chunck_Mg)
    counter = data_chunck_Mg.count(2)
    ones = data_chunck_Mg.count(1)
    transmission = counter/(counter+ones)
    resultsMg1MM.append((j, transmission))
result_array_Mg1MM = np.array(resultsMg1MM)
print("Printing results of Mg ----------------------------------")
print(result_array_Mg1MM)
print("---------------------------------------------------------")

resultsAl1MM = []
j = 1
for j in range(1, 31):
    data_chunck_Al = []
    for col1, col2 in dataAl1MM:
        if col1 == j:
            data_chunck_Al.append(col2)
    array_chunck = np.array(data_chunck_Al)
    counter = data_chunck_Al.count(2)
    ones = data_chunck_Al.count(1)
    transmission = counter/(counter+ones)
    resultsAl1MM.append((j, transmission))
result_array_Al1MM = np.array(resultsAl1MM)
print("Printing results of Al ----------------------------------")
print(result_array_Al1MM)
print("---------------------------------------------------------")

resultsTef100MIC = []
j = 1
for j in range(1, 31):
    data_chunck_Tef1 = []
    for col1, col2 in dataTef100MIC:
        if col1 == j:
            data_chunck_Tef1.append(col2)
    array_chunck = np.array(data_chunck_Tef1)
    counter = data_chunck_Tef1.count(2)
    ones = data_chunck_Tef1.count(1)
    transmission = counter/(counter+ones)
    resultsTef100MIC.append((j, transmission))
result_array_Tef100MIC = np.array(resultsTef100MIC)
print("Printing results of Teflon 100 --------------------------")
print(result_array_Tef100MIC)
print("---------------------------------------------------------")

resultsTef200MIC = []
j = 1
for j in range(1, 31):
    data_chunck_Tef2 = []
    for col1, col2 in dataTef200MIC:
        if col1 == j:
            data_chunck_Tef2.append(col2)
    array_chunck = np.array(data_chunck_Tef2)
    counter = data_chunck_Tef2.count(2)
    ones = data_chunck_Tef2.count(1)
    transmission = counter/(counter+ones)
    resultsTef200MIC.append((j, transmission))
result_array_Tef200MIC = np.array(resultsTef200MIC)
print("Printing results of Teflon 200 --------------------------")
print(result_array_Tef200MIC)
print("---------------------------------------------------------")

#plot
plt.plot(result_array_Be1MM[:,0], result_array_Be1MM[:,1], color='magenta', label="Be 1mm")
plt.plot(result_array_Mg1MM[:,0], result_array_Mg1MM[:,1], color='aqua', label="Mg 1mm")
plt.plot(result_array_Al1MM[:,0], result_array_Al1MM[:,1], color='green', label="Al 1mm")
plt.plot(result_array_Tef100MIC[:,0], result_array_Tef100MIC[:,1], color='coral', linestyle='--', label="Teflon 0.1mm")
plt.plot(result_array_Tef200MIC[:,0], result_array_Tef200MIC[:,1], color='plum', linestyle='--', label="Teflon 0.2mm")

plt.legend()
plt.xlabel("Energy (keV)")
plt.ylabel("Transmission")
plt.title("Transmission Be(1mm), Mg(1mm), Al(1mm), and Teflon(0.1mm/0.2mm)")
plt.show()