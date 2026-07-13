# User Documentation

This guide will help you understand, run, and manage the Inception project.

## Services Provided
The stack provides a complete, isolated web infrastructure consisting of three main services:
- **Nginx**: A web server that acts as the entry point, handling incoming HTTPS requests securely.
- **WordPress**: A content management system (CMS) where the website content is hosted and managed.
- **MariaDB**: A relational database that securely stores all of the WordPress site's data.

## Starting and Stopping the Project
The project is easily managed through a provided Makefile.

**To start the project:**
Open a terminal in the root directory and run:
```bash
make
```
This will build the containers (if they aren't built already) and start all the services in the background.

**To stop the project:**
Run the following command in the same directory:
```bash
make down
```
*(Alternatively, you can navigate to the `srcs` directory and run `docker compose down`).*

## Accessing the Website and Administration Panel
Once the project is successfully running:
- **Main Website**: Open your web browser and navigate to `https://dkhalfao.42.fr`.
- **Administration Panel**: Navigate to `https://dkhalfao.42.fr/wp-admin` to access the WordPress dashboard.
- **Static website**: Open your web browser and navigate to `http://khalfaouidriss:8080`.

*Note: Since this is a local environment using a self-signed certificate, your browser may display a security warning. You can safely bypass it to proceed.*

## Locating and Managing Credentials
All sensitive credentials (such as database passwords and WordPress administrator credentials) are securely stored in a `.env` file. 
- You must create or locate the `.env` file inside the `srcs/` directory before starting the project.
- To manage or update credentials, open and edit this `.env` file. Do not share this file publicly or commit it to version control.

## Checking if Services Are Running Correctly
You can verify the status of the services by running:
```bash
docker ps
```
This will list all active containers. You should see three containers running: one for `nginx`, one for `wordpress`, and one for `mariadb`.

If you encounter issues or need to view the logs for a specific service, use:
```bash
docker logs <container_name>
```
