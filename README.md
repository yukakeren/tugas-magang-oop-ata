# tugas-magang-oop-ata
tugas abinara1

# SQL Database Cheat Sheet
*A quick reference guide for SQL database operations*

## 1. Table Creation

### Create a Table with Primary and Foreign Keys
```sql
CREATE TABLE TableName (
    ColumnName DataType Constraints,
    ...
    FOREIGN KEY (ForeignKeyColumn) REFERENCES ReferencedTable(ReferencedColumn)
        ON UPDATE Action
        ON DELETE Action
);
```

### Example
```sql
CREATE TABLE Bagasi (
    ID INT PRIMARY KEY,
    Berat INT,
    Ukuran VARCHAR(5),
    Warna VARCHAR(255),
    Jenis VARCHAR(50)
);
```

## 2. Inserting Data

### Basic Insert Statement
```sql
INSERT INTO TableName VALUES (value1, value2, ...);
```

### Example
```sql
INSERT INTO Bagasi VALUES (1, 20, 'M', 'Hitam', 'Koper');
```

## 3. Altering Tables

### Add a New Column
```sql
ALTER TABLE TableName ADD COLUMN ColumnName DataType;
```

#### Example
```sql
ALTER TABLE Penumpang ADD COLUMN Email VARCHAR(255);
```

### Modify a Column's Data Type
```sql
ALTER TABLE TableName MODIFY ColumnName NewDataType;
```

#### Example
```sql
ALTER TABLE Bagasi MODIFY Jenis VARCHAR(50);
```

### Drop a Column
```sql
ALTER TABLE TableName DROP COLUMN ColumnName;
```

#### Example
```sql
ALTER TABLE Penumpang DROP COLUMN Email;
```

### Drop Primary Key and Change Primary Key Column
```sql
ALTER TABLE TableName
DROP PRIMARY KEY,
ADD PRIMARY KEY(NewPrimaryKeyColumn);
```

#### Example
```sql
ALTER TABLE Bandara
DROP PRIMARY KEY,
DROP COLUMN ID,
ADD PRIMARY KEY(Kode_IATA);
```

## 4. Deleting Tables

### Drop a Table
```sql
DROP TABLE TableName;
```

#### Example
```sql
DROP TABLE Bandara_penerbangan;
```

## 5. Updating Data

### Update Data in a Table
```sql
UPDATE TableName
SET ColumnName = NewValue, ...
WHERE Condition;
```

#### Examples
```sql
UPDATE Penumpang 
SET No_telepon = '081223344556' 
WHERE NIK = '3302134567890123';

UPDATE Penerbangan
SET Waktu_Keberangkatan = '2024-12-15 11:00:00',
    Waktu_Sampai = '2024-12-15 13:30:00'
WHERE ID = 'FL0001';
```

## 6. Deleting Data

### Delete Rows Matching a Condition
```sql
DELETE FROM TableName
WHERE Condition;
```

#### Examples
```sql
DELETE FROM Tiket 
WHERE Penumpang_NIK = '3504156789012345' 
AND Penerbangan_ID = 'FL0004';

DELETE FROM Bagasi WHERE ID = 2;
```

## 7. Foreign Keys & Relationships

### Define Foreign Key Relationships with Cascading Actions
```sql
FOREIGN KEY (ColumnName) REFERENCES ReferencedTable(ReferencedColumn)
    ON UPDATE CASCADE
    ON DELETE CASCADE
```

## 8. Composite Primary Keys

### Define Composite Primary Keys
```sql
CREATE TABLE TableName (
    Column1 DataType,
    Column2 DataType,
    PRIMARY KEY (Column1, Column2)
);
```

## Complete Example

```sql
-- Table creation with composite primary keys and foreign keys
CREATE TABLE Bandara_penerbangan (
    Bandara_ID CHAR(3),
    Penerbangan_ID CHAR(6),
    PRIMARY KEY (Bandara_ID, Penerbangan_ID),
    FOREIGN KEY (Bandara_ID) REFERENCES Bandara(Kode_IATA)
        ON UPDATE CASCADE
        ON DELETE CASCADE,
    FOREIGN KEY (Penerbangan_ID) REFERENCES Penerbangan(ID)
        ON UPDATE CASCADE
        ON DELETE CASCADE
);

-- Inserting data after modifying primary key column
INSERT INTO Bandara_penerbangan VALUES ('CGK', 'FL0001');
```

---

*Note: This cheat sheet serves as a quick reference for common SQL database operations. Use it alongside your database system's specific documentation for best results.*
