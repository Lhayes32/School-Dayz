import folium
import pandas as pd
import json
from folium import plugins

#Basic Point Map

df = pd.read_csv('starbucksInLACounty.csv')

with open('laMap.geojson') as f:
    laArea = json.load(f)

laMap = folium.Map(location=[34.0522, -118.2437], tiles='Stamen Toner', zoom_start=9)

folium.GeoJson(laArea).add_to(laMap)

for i, row in df.iterrows():
    folium.CircleMarker((row.latitude, row.longitude), radius=3, weight=2, color='red', fill_color='red', fill_opacity=.5).add_to(laMap)

laMap.save('laPointMap.html')

numStoresSeries = df.groupby('zip').count().id
numStoresByZip = pd.DataFrame()
numStoresByZip['zipcode'] = [str(i) for i in numStoresSeries.index]
numStoresByZip['numStores'] = numStoresSeries.values

laMap = folium.Map(location=[34.0522, -118.2437], titles='Stamen Toner', zoom_start=9)

laMap.choropleth(geo_data='laZips.geojson', data=numStoresByZip, columns=['zipcode', 'numStores'], \
                 key_on='feature.properties.zipcode', fill_color='YlGn', fill_opacity=1)

laMap.save('laChoropleth.html')

laMap = folium.Map(location=[34.0522, -118.2437], tiles='Stamen Toner', zoom_start=9)

folium.GeoJson(laArea).add_to(laMap)

for i,row in df.iterrows():
    folium.CircleMarker((row.latitude, row.longitude), radius=3, weight=2, color='red', fill_color='red', fill_opacity=.5).add_to(laMap)

laMap.add_children(plugins.HeatMap(data=df[['latitude', 'longitude']].as_matrix(), radius=25, blur=10))

laMap.save('laHeatmap.html')