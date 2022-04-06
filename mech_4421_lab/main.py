# this is written for the lab report for the course MECH 4421

import numpy as np
import matplotlib.pyplot as plt

x = np.array(['Water', 'Water + 0.0001M SDS', 'Water + 0.002M SDS', 'Commercial soap solution'])
sf = np.array([
    [74.5996, 73.4057, 74.6942],
    [66.6049, 61.2831, 65.7075],
    [59.2864, 62.4872, 59.6497],
    [28.4862, 28.8128, 28.1037]
])

def calc_error(data):
    avg = np.mean(data, axis=1)
    error = [[avg[i] - min(d), max(d) - avg[i]] for i, d in enumerate(data)]
    return np.transpose(error)

breakage = np.array([
    [0,0,0],
    [30,8,11],
    [13,18,11],
    [100,90,100]
])

def plot1():
    sf_avg = np.mean(sf, axis=1)
    sf_error = calc_error(sf)

    plt.figure(figsize=(8,5))

    ax = plt.axes()

    ax.set_ymargin(0.2)

    plt.errorbar(x, sf_avg, sf_error, fmt='-o', markersize=3)

    ax.set_xlabel('SDS concentration')
    ax.set_ylabel(r'Surface tension $\sigma$ (mN/m)')

    ax.axis('tight')

    plt.show()

def plot2():
    breakage_avg = np.mean(breakage, axis=1)
    breakage_error = calc_error(breakage)

    plt.figure(figsize=(8,5))

    ax = plt.axes()

    plt.errorbar(x, breakage_avg, breakage_error, fmt='-o', markersize=3)

    ax.set_xlabel('SDS concentration')
    ax.set_ylabel(r'Breakage time (s)')

    ax.axis('tight')

    plt.show()


def main():
    # plot1()
    plot2()

if __name__ == "__main__":
    main()
