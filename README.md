# Movie Recommender OOPs

## Project Structure

The project consists of two main folders: **backend** and **frontend**.

### Backend
The **backend** folder contains the C++ server code for the movie recommender system.

#### Directory Structure:
```
backend/
├── CMakeLists.txt
├── src/
│   └── main.cpp
└── include/
    └── server.h
```

### Frontend
The **frontend** folder contains the React application.

#### Directory Structure:
```
frontend/
├── public/
│   ├── index.html
│   └── favicon.ico
├── src/
│   ├── App.js
│   ├── index.js
│   └── components/
│       ├── MovieList.js
│       └── MovieItem.js
├── package.json
└── README.md
```

## Instructions to Set Up

1. ### Backend Setup
   - Navigate to the backend directory: `cd backend`
   - Run CMake to configure the project: `cmake .`
   - Build the project: `make`
   - Run the server: `./server`

2. ### Frontend Setup
   - Navigate to the frontend directory: `cd frontend`
   - Install dependencies: `npm install`
   - Start the React app: `npm start`
   
   The app will be available at [http://localhost:3000](http://localhost:3000).  
   Make sure to have Node.js and npm installed.
