import numpy as np
import matplotlib.pyplot as plt
W1 = np.random.randn(2, 5)
W2 = np.random.randn(5, 1)
lr = 0.01
path=r"C:\Users\Admin\Downloads\Grade Prediction\student-mat.csv"
def nn(x, t=None):
    global W1, W2
    x = np.array(x)
    t = np.array(t) if t is not None else None
    h = np.tanh(x @ W1)
    y = h @ W2
    if t is not None:
        e = y - t
        W2_old = W2.copy()
        W2 -= lr * h.T @ e
        W1 -= lr * x.T @ ((e @ W2_old.T) * (1 - h * h))
    return y
P, A = [], []
for _ in range(200):
    x = [np.random.rand() * 10, np.random.rand()]
    y = 5 * x[0] + 50 * x[1] + np.random.rand() * 5
    P.append(nn([x], [[y]])[0, 0])  # FIXED (P not p)
    A.append(y)
y = 0
Y = []
for _ in range(200):
    e = 1 - y
    u = nn([[e, -y]])
    y += 0.1 * u[0, 0]
    nn([[e, -y]], [[1]])
    Y.append(y)
X, P2, A2 = [], [], []
for _ in range(200):
    u = np.random.uniform(-1, 1)
    y = np.sin(2 * u) + 0.3 * u
    P2.append(nn([[u, 0]], [[y]])[0, 0])
    X.append(u)
    A2.append(y)
plt.figure(figsize=(10, 3))
plt.subplot(131)
plt.plot(A)
plt.plot(P)
plt.title("Grades")
plt.subplot(132)
plt.plot(Y)
plt.axhline(1, linestyle='--')
plt.title("Control")
plt.subplot(133)
plt.scatter(X, A2)
plt.scatter(X, P2)
plt.title("Process")
plt.tight_layout()
plt.show()
