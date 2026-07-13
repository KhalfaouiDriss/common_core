# Step 1: Use a tiny Python base image
FROM python:alpine

# Step 2: Set the working directory
WORKDIR /app

# Step 3: Copy your resume files into the container
COPY page/* /app

# Step 4: Expose port 8080
EXPOSE 8080

# Step 5: Start Python's built-in HTTP server module
CMD ["python", "-m", "http.server", "8080"]