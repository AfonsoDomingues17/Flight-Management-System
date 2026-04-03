# Flight Management System

A C++ system for querying and analysing a global flight network, modelled as a weighted directed graph. Built from scratch with a custom templated graph implementation supporting BFS-based shortest-path search, multi-criteria filtering, and coordinate-based airport lookup.

## Architecture

The flight network is represented as a directed graph where **vertices are Airports** and **edges are Flights**, each carrying an airline code. The graph is templated (`Graph<Airport>`) allowing reuse across different node types.

Data is loaded from three CSV files at startup:
- `airports.csv` — IATA code, name, city, country, latitude, longitude
- `airlines.csv` — code, name, callsign, country  
- `flights.csv` — source airport, destination airport, airline code

Lookup structures use `unordered_map` for O(1) access by airport code, airport name, and city.

## Features

### Flexible Source & Destination Input
Queries accept any combination of:
- Airport code (e.g. `LIS`, `JFK`)
- City name
- GPS coordinates (finds nearest airports automatically)

All 9 combinations are supported (airport→airport, airport→city, airport→coordinates, city→airport, city→city, city→coordinates, coordinates→airport, coordinates→city, coordinates→coordinates).

### Shortest Path Search
BFS-based shortest path returning **all** minimum-hop routes between two points, not just one. Handles cities with duplicate names across countries by prompting the user to disambiguate.

### Flight Filters
Three optional filters can be applied to any query:

| Filter | Description |
|--------|-------------|
| **F1** | Minimise number of different airlines used |
| **F2** | Restrict to a specific set of preferred airlines |
| **F3** | Avoid flights passing through specified countries |

### Graph Algorithms
- **BFS** — shortest path by number of hops
- **DFS** — full graph traversal from a source
- **Topological sort** — Kahn's algorithm with indegree tracking
- **DAG detection** — cycle detection via DFS processing stack
- **Indegree calculation** — O(V + E)

## Build

```bash
mkdir build && cd build
cmake ..
make
./GraphProject
```

## Tech

C++ · CMake · Custom templated graph · BFS · DFS · Topological sort · Haversine coordinate search · `unordered_map` for O(1) lookups
