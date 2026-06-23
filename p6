import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression
import os
path = r"C:\Users\Admin\Downloads\Energy Demand Forecasting\AEP_hourly.csv"
df = pd.read_csv(path)
df.iloc[:, 0] = pd.to_datetime(df.iloc[:, 0])
hours = df.iloc[:, 0].map(pd.Timestamp.timestamp).values.reshape(-1, 1)
demand = df.iloc[:, 1].values
model = LinearRegression()
model.fit(hours, demand)
future_hours = np.array([9, 10, 11]).reshape(-1, 1)
predicted = model.predict(future_hours)
print("Predicted Demand:", predicted)
plt.scatter(hours, demand, label="Actual Data")
plt.plot(hours, model.predict(hours), label="Regression Line")
plt.scatter(future_hours, predicted, color='red', label="Predicted")
plt.xlabel("Hours")
plt.ylabel("Electricity Demand")
plt.title("Energy Demand Forecasting")
plt.legend()
plt.show()
