#Python code to find transmission from real data
import matplotlib.pyplot as plt
import numpy as np

np.set_printoptions(suppress=True, precision=2)

data_Al_1mm_Ba133 = np.loadtxt("/home/skyes/Geant4_MSFC/GRango_Data/RealTransmissionData/Al_1mm_Ba133.txt", dtype=int)
data_Al_2mm_Ba133 = np.loadtxt("/home/skyes/Geant4_MSFC/GRango_Data/RealTransmissionData/Al_2mm_Ba133.txt", dtype=int)
data_Background = np.loadtxt("/home/skyes/Geant4_MSFC/GRango_Data/RealTransmissionData/Background.txt", dtype=int)
data_NoAl_Ba133 = np.loadtxt("/home/skyes/Geant4_MSFC/GRango_Data/RealTransmissionData/NoAl_Ba133.txt", dtype=int)

#Subtract background from data with 1 mm Al
bgSub_Al_1mm_Ba133 = data_Al_1mm_Ba133[:,1] - data_Background[:,1]
bgSub_Al_1mm_Ba133_arr = np.array(bgSub_Al_1mm_Ba133)
channel_arr_1 = np.array(data_Al_1mm_Ba133[:,0])
Al_1mm_Ba133_result= np.vstack((channel_arr_1, bgSub_Al_1mm_Ba133_arr)).T 


#Subtract background from data with 2 mm Al
bgSub_Al_2mm_Ba133 = data_Al_2mm_Ba133[:,1] - data_Background[:,1]
bgSub_Al_2mm_Ba133_arr = np.array(bgSub_Al_2mm_Ba133)
channel_arr_2 = np.array(data_Al_2mm_Ba133[:,0])
Al_2mm_Ba133_result= np.vstack((channel_arr_2, bgSub_Al_2mm_Ba133_arr)).T 

#Subtract background from data with no Al
bgSub_NoAl_Ba133 = data_NoAl_Ba133[:,1] - data_Background[:,1]
bgSub_NoAl_Ba133_arr = np.array(bgSub_NoAl_Ba133)
channel_arr_0 = np.array(data_NoAl_Ba133[:,0])
NoAl_Ba133_result= np.vstack((channel_arr_0, bgSub_NoAl_Ba133_arr)).T

#Get the counts for 30.85 keV peak with no Al
channel_NoAl_30, counts_NoAl_30 = NoAl_Ba133_result.T
mask_NoAl_30 = (479 < channel_NoAl_30) & (channel_NoAl_30 < 526)
total_NoAl_30 = counts_NoAl_30[mask_NoAl_30].sum()
print("counts for 30.85 keV peak with no Al", total_NoAl_30)

#Get the transmission ratio for the Ba133 30.85 keV line at 1mm
channel_Al1mm_30, counts_Al1mm_30 = Al_1mm_Ba133_result.T
mask_Al1mm_30 = (479 < channel_Al1mm_30) & (channel_Al1mm_30 < 526)
total_Al1mm_30 = counts_Al1mm_30[mask_Al1mm_30].sum()
print("counts for 30.85 keV peak with 1mm Al", total_Al1mm_30)
print("30.85 keV line trans ratio 1mm: ", total_Al1mm_30/total_NoAl_30)

#Get the transmission ratio for the Ba133 30.85 keV line at 2 mm
channel_Al2mm_30, counts_Al2mm_30 = Al_2mm_Ba133_result.T
mask_Al2mm_30 = (479 < channel_Al2mm_30) & (channel_Al2mm_30 < 526)
total_Al2mm_30 = counts_Al2mm_30[mask_Al2mm_30].sum()
print("counts for 30.85 keV peak with 2mm Al", total_Al2mm_30)
print("30.85 keV line trans ratio 2mm: ", total_Al2mm_30/total_NoAl_30)

#Get the counts for 81.00 keV peak with no Al
energy_NoAl_81, counts_NoAl_81 = NoAl_Ba133_result.T
mask_NoAl_81 = (1267 < energy_NoAl_81) & (energy_NoAl_81 < 1316)
total_NoAl_81 = counts_NoAl_81[mask_NoAl_81].sum()
print("counts for 81.00 keV peak with no Al", total_NoAl_81)

#Get the transmission ratio for the Ba133 81.00 keV line at 1mm
energy_Al1mm_81, counts_Al1mm_81 = Al_1mm_Ba133_result.T
mask_Al1mm_81 = (1267 < energy_Al1mm_81) & (energy_Al1mm_81 < 1316)
total_Al1mm_81 = counts_Al1mm_81[mask_Al1mm_81].sum()
print("counts for 81.00 keV peak with 1mm Al", total_Al1mm_81)
print("81.00 keV line trans ratio 1mm: ", total_Al1mm_81/total_NoAl_81)

#Get the transmission ratio for the Ba133 81.00 keV line at 2mm
energy_Al2mm_81, counts_Al2mm_81 = Al_2mm_Ba133_result.T
mask_Al2mm_81 = (1267 < energy_Al2mm_81) & (energy_Al2mm_81 < 1316)
total_Al2mm_81 = counts_Al2mm_81[mask_Al2mm_81].sum()
print("counts for 81.00 keV peak with 2mm Al", total_Al2mm_81)
print("81.00 keV line trans ratio 2mm: ", total_Al2mm_81/total_NoAl_81)


#Same thing for Cd109
data_Al_1mm_Cd109 = np.loadtxt("/home/skyes/Geant4_MSFC/GRango_Data/RealTransmissionData/Al_1mm_Cd109.txt", dtype=int)
data_Al_2mm_Cd109 = np.loadtxt("/home/skyes/Geant4_MSFC/GRango_Data/RealTransmissionData/Al_2mm_Cd109.txt", dtype=int)
data_Background = np.loadtxt("/home/skyes/Geant4_MSFC/GRango_Data/RealTransmissionData/Background.txt", dtype=int)
data_NoAl_Cd109 = np.loadtxt("/home/skyes/Geant4_MSFC/GRango_Data/RealTransmissionData/NoAl_Cd109.txt", dtype=int)

#Subtract background from data with 1 mm Al
bgSub_Al_1mm_Cd109 = data_Al_1mm_Cd109[:,1] - data_Background[:,1]
bgSub_Al_1mm_Cd109_arr = np.array(bgSub_Al_1mm_Cd109)
channel_arr_1 = np.array(data_Al_1mm_Cd109[:,0])
Al_1mm_Cd109_result= np.vstack((channel_arr_1, bgSub_Al_1mm_Cd109_arr)).T 

#Subtract background from data with 2 mm Al
bgSub_Al_2mm_Cd109 = data_Al_2mm_Cd109[:,1] - data_Background[:,1]
bgSub_Al_2mm_Cd109_arr = np.array(bgSub_Al_2mm_Cd109)
channel_arr_2 = np.array(data_Al_2mm_Cd109[:,0])
Al_2mm_Cd109_result= np.vstack((channel_arr_2, bgSub_Al_2mm_Cd109_arr)).T 

#Subtract background from data with no Al
bgSub_NoAl_Cd109 = data_NoAl_Cd109[:,1] - data_Background[:,1]
bgSub_NoAl_Cd109_arr = np.array(bgSub_NoAl_Cd109)
channel_arr_0 = np.array(data_NoAl_Cd109[:,0])
NoAl_Cd109_result= np.vstack((channel_arr_0, bgSub_NoAl_Cd109_arr)).T

#Get the counts for 22.10 keV peak with no Al
channel_NoAl_22, counts_NoAl_22 = NoAl_Cd109_result.T
mask_NoAl_22 = (317 < channel_NoAl_22) & (channel_NoAl_22 < 366)
total_NoAl_22 = counts_NoAl_22[mask_NoAl_22].sum()
print("counts for 22.10 keV peak with no Al", total_NoAl_22)

#Get the transmission ratio for the Cd109 22.10 keV line at 1mm
channel_Al1mm_22, counts_Al1mm_22 = Al_1mm_Cd109_result.T
mask_Al1mm_22 = (317 < channel_Al1mm_22) & (channel_Al1mm_22 < 366)
total_Al1mm_22 = counts_Al1mm_22[mask_Al1mm_22].sum()
print("counts for 22.10 keV peak with 1mm Al", total_Al1mm_22)
print("22.10 keV line trans ratio 1mm: ", total_Al1mm_22/total_NoAl_22)

#Get the transmission ratio for the Cd109 22.85 keV line at 2 mm
channel_Al2mm_22, counts_Al2mm_22 = Al_2mm_Cd109_result.T
mask_Al2mm_22 = (317 < channel_Al2mm_22) & (channel_Al2mm_22 < 366)
total_Al2mm_22 = counts_Al2mm_22[mask_Al2mm_22].sum()
print("counts for 22.10 keV peak with 2mm Al", total_Al2mm_22)
print("22.10 keV line trans ratio 2mm: ", total_Al2mm_22/total_NoAl_22)

#Get the counts for 25.00 keV peak with no Al
energy_NoAl_25, counts_NoAl_25 = NoAl_Cd109_result.T
mask_NoAl_25 = (377 < energy_NoAl_25) & (energy_NoAl_25 < 418)
total_NoAl_25 = counts_NoAl_25[mask_NoAl_25].sum()
print("counts for 25.00 keV peak with no Al", total_NoAl_25)

#Get the transmission ratio for the Cd109 25.00 keV line at 1mm
energy_Al1mm_25, counts_Al1mm_25 = Al_1mm_Cd109_result.T
mask_Al1mm_25 = (377 < energy_Al1mm_25) & (energy_Al1mm_25 < 418)
total_Al1mm_25 = counts_Al1mm_25[mask_Al1mm_25].sum()
print("counts for 25.00 keV peak with 1mm Al", total_Al1mm_25)
print("25.00 keV line trans ratio 1mm: ", total_Al1mm_25/total_NoAl_25)

#Get the transmission ratio for the Cd109 25.00 keV line at 2mm
energy_Al2mm_25, counts_Al2mm_25 = Al_2mm_Cd109_result.T
mask_Al2mm_25 = (377 < energy_Al2mm_25) & (energy_Al2mm_25 < 418)
total_Al2mm_25 = counts_Al2mm_25[mask_Al2mm_25].sum()
print("counts for 25.00 keV peak with 2mm Al", total_Al2mm_25)
print("25.00 keV line trans ratio 2mm: ", total_Al2mm_25/total_NoAl_25)