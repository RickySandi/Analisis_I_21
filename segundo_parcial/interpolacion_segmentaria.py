import numpy as np    
from scipy.interpolate import interp1d                    # numerics
# import matplotlib.pyplot as plt           # plotting
# matplotlib inline    

# xg = np.array([0.2, 0.6, 1.2, 1.4, 1.8])   # given x data
# yg = np.array([0.20, 0.55, 0.21, 0.22, 0.44])   # given y data

xg = np.array([0.6, 1.2])   # given x data
yg = np.array([0.55, 0.21])   # given y data



#---------------

f_interp = interp1d(xg, yg)

#---------------

xw = 0.8
yw = f_interp(xw)

print(yw)
