import pandas as pd
import matplotlib.pyplot as plt

thisdict = {
    "brand": "Fords",
    "model": "Mustang",
    "year": 1964
}

# print(thisdict)
# print(thisdict["model"])
# print(thisdict.get("model"))
# thisdict["year"] = 2020

# for x in thisdict:
#     print(x)


data = [{'area' : 'California', 'pop' : 38332521, 'year' : 2013},
        {'area' : 'Texas', 'pop' : 26448193, 'year' : 2013},
        {'area' : 'New York', 'pop' : 19651127, 'year' : 2013},
        {'area' : 'Florida', 'pop' : 19552860, 'year' : 2013},
        {'area' : 'Illinois', 'pop' : 12882135, 'year' : 2013}]     

df = pd.DataFrame.from_dict(data)
# print(df)


# plt.plot(df['area'], df['pop'])
# plt.show()


# read from csv
# df = pd.read_csv('E:\college_class\aiML\pandas\l.csv')
# print(df)