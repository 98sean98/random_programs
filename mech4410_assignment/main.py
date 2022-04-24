import numpy as np
import matplotlib.pyplot as plt

def main():
    x1 = np.linspace(0, 3.75, 100)
    y1 = -4 / 3 * x1 + 5

    x2 = np.linspace(0, 4.5, 100)
    y2 = - x2 + 9 / 2

    x3 = np.linspace(0, 6, 100)
    y3 = - x3 / 3 + 2

    plt.figure(figsize=(8,5))

    ax = plt.axes()
    ax.plot(x1, y1, label='40x+30y=150')
    ax.plot(x2, y2, label='20x+20y=90')
    ax.plot(x3, y3, label='10x+30y=60')

    ax.set_xlabel("Bag A (x)")
    ax.set_ylabel("Bag B (y)")

    ax.axis('tight')
    plt.legend()
    plt.show()

if __name__ == '__main__':
    main()
