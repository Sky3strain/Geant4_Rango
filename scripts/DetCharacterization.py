import matplotlib.pyplot as plt
import numpy as np
import sys

data_CsI_Tl = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/plots/EffectiveAreaStudies/EffectiveArea_CsI_Tl.txt", delimiter=",", dtype=float)
data_CeBr3 = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/plots/EffectiveAreaStudies/EffectiveArea_CeBr3.txt", delimiter=",", dtype=float)
data_NaI_Tl = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/plots/EffectiveAreaStudies/EffectiveArea_NaI_Tl.txt", delimiter=",", dtype=float)
data_BGO = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/plots/EffectiveAreaStudies/EffectiveArea_BGO.txt", delimiter=",", dtype=float)
dataBe1MM = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/plots/TransmissionStudies/Transmission_1-10000keV_Be1MM.txt", delimiter=',', dtype=float)
dataMg1MM = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/plots/TransmissionStudies/Transmission_1-10000keV_Mg1MM.txt", delimiter=',', dtype=float)
dataAl1MM = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/plots/TransmissionStudies/Transmission_1-10000keV_Al1MM.txt", delimiter=',', dtype=float)
dataAl2MM = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/plots/TransmissionStudies/Transmission_1-10000keV_Al2MM.txt", delimiter=',', dtype=float)
dataTef100MIC = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/plots/TransmissionStudies/Transmission_1-10000keV_Tef0.1MM.txt", delimiter=',', dtype=float)
dataTef200MIC = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/plots/TransmissionStudies/Transmission_1-10000keV_Tef0.2MM.txt", delimiter=',', dtype=float)

print("Detector Choices: ")
print("(1) CsI_Tl ")
print("(2) NaI_Tl ")
print("(3) CeBr3 ")
print("(4) BGO ")
det_input = input("Choose Your Detector (type the number associated with the detector): ")
det_data = []
if (det_input == "1"):
    print("Detector Selected: CsI_Tl")
    det_data = data_CsI_Tl
    det_name = "CsI_Tl"
elif (det_input == "2"):
    det_data = data_NaI_Tl
    print("Detector Selected: NaI_Tl")
    det_name = "NaI_Tl"
elif (det_input == "3"):
    det_data = data_CeBr3
    print("Detector Selected: CeBr3")
    det_name = "CeBr3"
elif (det_input == "4"):
    det_data = data_BGO
    print("Detector Selected: BGO")
    det_name = "BGO"
else:
    print("Must Enter A Detector To Continue!")
    sys.exit()

print("Window Choices (type the number associated with the window): ")
print("(1) Be_1mm ")
print("(2) Mg_1mm ")
print("(3) Al_1mm ")
print("(4) Al_2mm ")
print("(5) Teflon_0.1mm-0.2mm")
print("(6) No Window")
win_input_1 = input("Choose Your First Window: ")

if (win_input_1 == "1"):
    win_data_1 = dataBe1MM
    print("Window Selected: Be_1mm")
    data_name_win1 = "Be_1mm"
elif (win_input_1 == "2"):
    win_data_1 = dataMg1MM
    print("Window Selected: Mg_1mm")
    data_name_win1 = "Mg_1mm"
elif (win_input_1 == "3"):
    win_data_1 = dataAl1MM
    print("Window Selected: Al_1mm")
    data_name_win1 = "Al_1mm"
elif (win_input_1 == "4"):
    win_data_1 = dataAl2MM
    print("Window Selected: Al_2mm")
    data_name_win1 = "Al_2mm"
elif (win_input_1 == "5"):
    win_data_Tef1= dataTef100MIC
    win_data_Tef2= dataTef200MIC
    print("Window Selected: Teflon_0.1mm-0.2mm")
    data_name_win1 = "Teflon_0.1mm-0.2mm"
elif (win_input_1 == "6"):
    win_data_1 =  np.column_stack((det_data[:,0], np.ones(len(det_data))))
    print("Window Selected: No Window")
    data_name_win1 = "No Window"
else:
    print("Must Enter A Window To Continue!")
    sys.exit()

print("Window Choices (type the number associated with the window): ")
print("Warning!: Teflon is no longer an option.")
print("(1) Be_1mm ")
print("(2) Mg_1mm ")
print("(3) Al_1mm ")
print("(4) Al_2mm ")
print("(5) No Window")
win_input_2 = input("Choose Your Second Window: ")
print("You entered:", win_input_2)

if (win_input_2 == "1"):
    win_data_2 = dataBe1MM
    print("Window Selected: Be_1mm")
    data_name_win2 = "Be_1mm"
elif (win_input_2 == "2"):
    win_data_2 = dataMg1MM
    print("Window Selected: Mg_1mm")
    data_name_win2 = "Mg_1mm"
elif (win_input_2 == "3"):
    win_data_2 = dataAl1MM
    print("Window Selected: Al_1mm")
    data_name_win2 = "Al_1mm"
elif (win_input_2 == "4"):
    win_data_2 = dataAl2MM
    print("Window Selected: Al_2mm")
    data_name_win2 = "Al_2mm"
elif (win_input_2 == "5"):
    win_data_2 =  np.column_stack((det_data[:,0], np.ones(len(det_data))))
    print("Window Selected: No Window")
    data_name_win2 = "No Window"
else:
    print("Must Enter A Window To Continue!")
    sys.exit()

#Find the effectice area with transmission from the first window
if win_input_1 == "5":
    start_energy_Tef1 = win_data_Tef1[0,0]
    start_index_Tef1 = np.where(det_data[:,0] >= start_energy_Tef1)[0][0]
    detdata_filt_Tef1 = det_data[start_index_Tef1:, :]

    start_energy_Tef2 = win_data_Tef2[0,0]
    start_index_Tef2 = np.where(det_data[:,0] >= start_energy_Tef2)[0][0]
    detdata_filt_Tef2 = det_data[start_index_Tef2:, :]

    Aeff_Tef1 = np.column_stack((detdata_filt_Tef1[:,0], detdata_filt_Tef1[:,1] * win_data_Tef1[:,1]))
    Aeff_Tef2 = np.column_stack((detdata_filt_Tef2[:,0], detdata_filt_Tef2[:,1] * win_data_Tef2[:,1]))
else:
    start_energy_1 = win_data_1[0,0]
    start_index_1 = np.where(det_data[:,0] >= start_energy_1)[0][0]
    detdata_filt_1 = det_data[start_index_1:, :]

    Aeff_1 = np.column_stack((detdata_filt_1[:,0], detdata_filt_1[:,1] * win_data_1[:,1]))

#Find the effectice area with transmission from the second window
if win_input_2 != "5" and win_input_1 != "5":
    if(len(detdata_filt_1) > len(win_data_2)):
        start_energy_2 = win_data_2[0,0]
        start_index_2 = np.where(detdata_filt_1[:,0] >= start_energy_2)[0][0]
        detdata_filt_2 = Aeff_1[start_index_2:, :]
        Aeff_2 = np.column_stack((detdata_filt_2[:,0], detdata_filt_2[:,1] * win_data_2[:,1]))
    else: 
        start_energy_2 = detdata_filt_1[0,0]
        start_index_2 = np.where(win_data_2[:,0] >= start_energy_2)[0][0]
        windata_filt_2 = win_data_2[start_index_2:, :]
        Aeff_2 = np.column_stack((windata_filt_2[:,0], windata_filt_2[:,1] * Aeff_1[:,1]))
    plt.ylim(0,130)
    plt.xlim(1, 12000)
    plt.plot(Aeff_2[:,0], Aeff_2[:,1], alpha = 0.5, color = 'magenta')
    plt.xscale('log')
    plt.xticks(fontsize=16)
    plt.yticks(fontsize=16)
    plt.xlabel("Energy (keV)", fontsize=16)
    plt.ylabel("Effective Area (cm^2)", fontsize=16)
    plt.title(f"{det_name} Effective Area With {data_name_win1} And {data_name_win2}", fontsize=16)
    plt.show()

if win_input_1 == "5":
    if(len(detdata_filt_Tef1) > len(win_data_2)):
        start_energy_Tef3 = win_data_2[0,0]
        start_index_Tef3 = np.where(detdata_filt_Tef1[:,0] >= start_energy_Tef3)[0][0]
        detdata_filt_Tef3 = Aeff_Tef1[start_index_Tef3:, :]
        Aeff_Tef3 = np.column_stack((detdata_filt_Tef3[:,0], detdata_filt_Tef3[:,1] * win_data_2[:,1]))
    else: 
        start_energy_Tef3 = detdata_filt_Tef1[0,0]
        start_index_Tef3 = np.where(win_data_2[:,0] >= start_energy_Tef3)[0][0]
        windata_filt_Tef3 = win_data_2[start_index_Tef3:, :]
        Aeff_Tef3 = np.column_stack((windata_filt_Tef3[:,0], windata_filt_Tef3[:,1] * Aeff_Tef1[:,1]))
    
    if(len(detdata_filt_Tef2) > len(win_data_2)):
        start_energy_Tef4 = win_data_2[0,0]
        start_index_Tef4 = np.where(detdata_filt_Tef2[:,0] >= start_energy_Tef4)[0][0]
        detdata_filt_Tef4 = Aeff_Tef2[start_index_Tef4:, :]
        Aeff_Tef4 = np.column_stack((detdata_filt_Tef4[:,0], detdata_filt_Tef4[:,1] * win_data_2[:,1]))
    else: 
        start_energy_Tef4 = detdata_filt_Tef2[0,0]
        start_index_Tef4 = np.where(win_data_2[:,0] >= start_energy_Tef4)[0][0]
        windata_filt_Tef4 = win_data_2[start_index_Tef4:, :]
        Aeff_Tef4 = np.column_stack((windata_filt_Tef4[:,0], windata_filt_Tef4[:,1] * Aeff_Tef2[:,1]))
    plt.ylim(0,130)
    plt.xlim(1, 12000)
    plt.plot(Aeff_Tef3[:,0], Aeff_Tef3[:,1], alpha = 0.5, color = 'magenta')
    plt.plot(Aeff_Tef4[:,0], Aeff_Tef4[:,1], alpha = 0.5, color = 'darkmagenta')
    plt.fill_between(Aeff_Tef3[:,0], Aeff_Tef3[:,1], Aeff_Tef4[:,1], color='salmon', alpha=0.5)
    plt.xscale('log')
    plt.xticks(fontsize=16)
    plt.yticks(fontsize=16)
    plt.xlabel("Energy (keV)", fontsize=16)
    plt.ylabel("Effective Area (cm^2)", fontsize=16)
    plt.title(f"{det_name} Effective Area With {data_name_win1} And {data_name_win2}", fontsize=16)
    plt.show()

