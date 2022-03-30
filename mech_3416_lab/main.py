# this is written for the lab report for the course MECH 3416

import numpy as np
from sklearn.linear_model import LinearRegression
import matplotlib.pyplot as plt

al = np.array([[1, 0.34], [2, 0.68], [3, 1.06], [4, 1.45]])
ti = np.array([[1, 0.17], [2, 0.45], [3, 0.72], [4, 0.95]])
comp = np.array([[4.905, 0.18], [9.81, 0.38], [14.715, 0.57], [19.62, 0.77]])

al_linspace = [0, 5, 100]
ti_linspace = [0, 5, 100]
comp_linspace = [0, 20, 100]

def main():
    beam = comp
    x_linspace = comp_linspace
    x = beam[:, 0].reshape((-1, 1))
    y = beam[:, 1]

    # do not calculate intercept by assuming it as 0
    model = LinearRegression(fit_intercept = False)

    model.fit(x, y)

    print('slope:', model.coef_)

    x_new = np.linspace(x_linspace[0], x_linspace[1], x_linspace[2])
    y_new = model.predict(x_new[:, np.newaxis])

    plt.figure(figsize=(8, 5))
    ax = plt.axes()
    ax.scatter(x, y)
    ax.plot(x_new, y_new)

    ax.set_xlabel('Force (N)')
    ax.set_ylabel(r'Deflection $\delta$ (mm)')

    ax.axis('tight')

    plt.show()

if __name__ == '__main__':
    main()
