#if defined _INC_omp_database
	#endinput
#endif
#define _INC_omp_database

// Backwards-compatibility.
#define _sampdb_included
#define _INC_a_sampdb

/**
 * <library name="omp_database" summary="open.mp SQLite functions.">
 *   <license>
 *     (c) Copyright 2022, open.mp team.
 *   </license>
 *   <summary pawndoc="true">
 *     This library uses the enhanced <em>pawndoc.xsl</em> from
 *     <a href="https://github.com/pawn-lang/pawndoc">pawn-lang/pawndoc</a>.
 *     This XSL has features such as library and markdown support, and will not
 *     render this message when used.
 *   </summary>
 * </library>
 */

/// <p/>

#pragma tabsize 4

/**
 * <library>omp_database</library>
 * <summary>This function is used to open a connection to a SQLite database, which is inside the <b><c>/scriptfiles</c></b>
 * folder.</summary>
 * <param name="name">File name of the database</param>
 * <remarks>
 *   It will create a new SQLite database, if there is no SQLite database with the same file name available.<br
 * />
 *   <b>Close</b> your database connection with <a href="#db_close">db_close</a>!
 * </remarks>
 * <returns>Returns index (starting at <b><c>1</c></b>) of the database connection .</returns>
 */
native DB:DB_Open(const name[]) = db_open;

/**
 * <library>omp_database</library>
 */
#pragma deprecated Use `DB_Open`.
native DB:db_open(const name[]);

/**
 * <library>omp_database</library>
 * <summary>Closes an SQLite database that was opened with <a href="#db_open">db_open</a>.</summary>
 * <param name="db">The handle of the database connection to close (returned by <a href="#db_open">db_open</a>)</param>
 * <remarks>Using an <b>invalid handle</b> will crash your server! Get a <b>valid handle</b> by using
 * <a href="#db_open">db_open</a>.  But it's protected against <b><c>NULL</c></b> references</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  May mean that the database handle specified is
 * not open.
 * </returns>
 */
native bool:DB_Close(DB:db) = db_close;

/**
 * <library>omp_database</library>
 */
#pragma deprecated Use `DB_Close`.
native bool:db_close(DB:db);

/**
 * <library>omp_database</library>
 * <summary>This function is used to execute an SQL query on an opened SQLite database.</summary>
 * <param name="db">The database handle to query</param>
 * <param name="query">The query to execute</param>
 * <remarks><b>Always</b> free the result by using <a href="#db_free_result">db_free_result</a>!</remarks>
 * <returns>The query result index (<b>starting at 1</b>).</returns>
 */
native DBResult:DB_ExecuteQuery(DB:db, const query[]) = db_query;

/**
 * <library>omp_database</library>
 */
#pragma deprecated Use `DB_ExecuteQuery`.
native DBResult:db_query(DB:db, const query[]);

/**
 * <library>omp_database</library>
 * <summary>Frees result memory allocated from <a href="#db_query">db_query</a>.</summary>
 * <param name="result">The result to free</param>
 * <returns>If <b><c>DBResult:dbhandle</c></b> is a valid handle, it returns <b><c>1</c></b>, otherwise
 * <b><c>0</c></b> if <b><c>DBResult:dbhandle</c></b> is a <b><c>NULL</c></b> reference.</returns>
 */
native bool:DB_FreeResultSet(DBResult:result) = db_free_result;

/**
 * <library>omp_database</library>
 */
#pragma deprecated Use `DB_FreeResult`.
native bool:db_free_result(DBResult:result);

/**
 * <library>omp_database</library>
 * <summary>Returns the number of rows from a <a href="#db_query">db_query</a>.</summary>
 * <param name="result">The result of <a href="#db_query">db_query</a></param>
 * <remarks>Using an <b>invalid handle</b> will crash your server! Get a <b>valid handle</b> by using
 * <a href="#db_open">db_open</a>.  But it's protected against <b><c>NULL</c></b> references</remarks>
 * <returns>The number of rows in the result.</returns>
 */
native DB_GetRowCount(DBResult:result) = db_num_rows;

/**
 * <library>omp_database</library>
 */
#pragma deprecated Use `DB_GetRowCount`.
native db_num_rows(DBResult:result);

/**
 * <library>omp_database</library>
 * <summary>Moves to the next row of the result allocated from <a href="#db_query">db_query</a>.</summary>
 * <param name="result">The result of <a href="#db_query">db_query</a></param>
 * <remarks>Using an <b>invalid handle</b> will crash your server! Get a <b>valid handle</b> by using
 * <a href="#db_open">db_open</a>.  But it's protected against <b><c>NULL</c></b> references</remarks>
 * <returns>Returns <b><c>1</c></b> on success, otherwise <b><c>0</c></b> if <b><c>DBResult:result</c></b>
 * is a <b><c>NULL</c></b> reference or the last row is reached.</returns>
 */
native bool:DB_SelectNextRow(DBResult:result) = db_next_row;

/**
 * <library>omp_database</library>
 */
#pragma deprecated Use `DB_SelectNextRow`.
native bool:db_next_row(DBResult:result);

/**
 * <library>omp_database</library>
 * <summary>Get the number of fields in a result.</summary>
 * <param name="result">The result of <a href="#db_query">db_query</a></param>
 * <remarks>Using an <b>invalid handle</b> will crash your server! Get a <b>valid handle</b> by using
 * <a href="#db_open">db_open</a>.  But it's protected against <b><c>NULL</c></b> references</remarks>
 * <returns>The number of fields in the result.</returns>
 */
native DB_GetFieldCount(DBResult:result) = db_num_fields;

/**
 * <library>omp_database</library>
 */
#pragma deprecated Use `DB_GetFieldCount`.
native db_num_fields(DBResult:result);

/**
 * <library>omp_database</library>
 * <summary>Returns the name of a field at a particular index.</summary>
 * <param name="result">The result to get the data from; returned by <a href="#db_query">db_query</a></param>
 * <param name="field">The index of the field to get the name of</param>
 * <param name="output">The returned value</param>
 * <param name="size">The max length of the field</param>
 * <remarks>Using an <b>invalid handle</b> will crash your server! Get a <b>valid handle</b> by using
 * <a href="#db_open">db_open</a>.  But it's protected against <b><c>NULL</c></b> references</remarks>
 * <returns>Returns <b><c>1</c></b>, if the function was successful, otherwise <b><c>0</c></b> if <b><c>DBResult:result</c></b>
 * is a <b><c>NULL</c></b> reference or the column index not available.</returns>
 */
native bool:DB_GetFieldName(DBResult:result, field, output[], size = sizeof (output)) = db_field_name;

/**
 * <library>omp_database</library>
 */
#pragma deprecated Use `DB_GetFieldName`.
native bool:db_field_name(DBResult:result, field, output[], size = sizeof (output));

/**
 * <library>omp_database</library>
 * <summary>Get the content of a field from <a href="#db_query">db_query</a>.</summary>
 * <param name="result">The result to get the data from</param>
 * <param name="field">The field to get the data from</param>
 * <param name="output">The returned value</param>
 * <param name="size">The max length of the field</param>
 * <remarks>Using an <b>invalid handle</b> will crash your server! Get a <b>valid handle</b> by using
 * <a href="#db_open">db_open</a>.  But it's protected against <b><c>NULL</c></b> references</remarks>
 * <returns>Returns <b><c>1</c></b> if successful, otherwise <b><c>0</c></b> if <b><c>DBResult:result</c></b>
 * is a <b><c>NULL</c></b> reference or the column index not available.</returns>
 */
native bool:DB_GetFieldString(DBResult:result, field, output[], size = sizeof (output)) = db_get_field;

/**
 * <library>omp_database</library>
 */
#pragma deprecated Use `DB_GetFieldString`.
native bool:db_get_field(DBResult:result, field, output[], size = sizeof (output));

/**
 * <library>omp_database</library>
 * <summary>Get the content of a field as an integer from <a href="#db_query">db_query</a>.</summary>
 * <param name="result">The result to get the data from</param>
 * <param name="field">The field to get the data from (optional=<b><c>0</c></b>)</param>
 * <remarks>Using an <b>invalid handle</b> will crash your server! Get a <b>valid handle</b> by using
 * <a href="#db_open">db_open</a>.  But it's protected against <b><c>NULL</c></b> references</remarks>
 * <returns>Retrieved value as integer (number).</returns>
 */
native DB_GetFieldInt(DBResult:result, field = 0) = db_get_field_int;

/**
 * <library>omp_database</library>
 */
#pragma deprecated Use `DB_GetFieldInt`.
native db_get_field_int(DBResult:result, field = 0);

/**
 * <library>omp_database</library>
 * <summary>Get the content of a field as a float from db_query.</summary>
 * <param name="result">The result to get the data from</param>
 * <param name="field">The field to get the data from (optional=<b><c>0</c></b>)</param>
 * <remarks>Using an <b>invalid handle</b> will crash your server! Get a <b>valid handle</b> by using
 * <a href="#db_open">db_open</a>.  But it's protected against <b><c>NULL</c></b> references</remarks>
 * <returns>Retrieved value as floating point number.</returns>
 */
native Float:DB_GetFieldFloat(DBResult:result, field = 0) = db_get_field_float;

/**
 * <library>omp_database</library>
 */
#pragma deprecated Use `DB_GetFieldFloat`.
native Float:db_get_field_float(DBResult:result, field = 0);

/**
 * <library>omp_database</library>
 * <summary>Get the contents of field with specified name.</summary>
 * <param name="result">The result to get the data from</param>
 * <param name="field">The fieldname to get the data from</param>
 * <param name="output">The returned value</param>
 * <param name="size">The max length of the field</param>
 * <remarks>Using an <b>invalid handle</b> will crash your server! Get a <b>valid handle</b> by using
 * <a href="#db_open">db_open</a>.  But it's protected against <b><c>NULL</c></b> references</remarks>
 * <returns>Returns <b><c>1</c></b> if successful, otherwise <b><c>0</c></b> if <b><c>DBResult:result</c></b>
 * is a <b><c>NULL</c></b> reference or the column index not available.</returns>
 */
native bool:DB_GetFieldStringByName(DBResult:result, const field[], output[], size = sizeof (output)) = db_get_field_assoc;

/**
 * <library>omp_database</library>
 */
#pragma deprecated Use `DB_GetFieldStringByName`.
native bool:db_get_field_assoc(DBResult:result, const field[], output[], size = sizeof (output));

/**
 * <library>omp_database</library>
 * <summary>Get the contents of field as an integer with specified name.</summary>
 * <param name="result">The result to get the data from</param>
 * <param name="field">The fieldname to get the data from</param>
 * <remarks>Using an <b>invalid handle</b> will crash your server! Get a <b>valid handle</b> by using
 * <a href="#db_open">db_open</a>.  But it's protected against <b><c>NULL</c></b> references</remarks>
 * <returns>Retrieved value as integer (number).</returns>
 */
native DB_GetFieldIntByName(DBResult:result, const field[]) = db_get_field_assoc_int;

/**
 * <library>omp_database</library>
 */
#pragma deprecated Use `DB_GetFieldIntByName`.
native db_get_field_assoc_int(DBResult:result, const field[]);

/**
 * <library>omp_database</library>
 * <summary>Get the contents of field as a float with specified name.</summary>
 * <param name="result">The result to get the data from</param>
 * <param name="field">The fieldname to get the data from</param>
 * <remarks>Using an <b>invalid handle</b> will crash your server! Get a <b>valid handle</b> by using
 * <a href="#db_open">db_open</a>.  But it's protected against <b><c>NULL</c></b> references</remarks>
 * <returns>Retrieved value as floating point number.</returns>
 */
native Float:DB_GetFieldFloatByName(DBResult:result, const field[]) = db_get_field_assoc_float;

/**
 * <library>omp_database</library>
 */
#pragma deprecated Use `DB_GetFieldFloatByName`.
native Float:db_get_field_assoc_float(DBResult:result, const field[]);

/**
 * <library>omp_database</library>
 * <summary>Get memory handle for an SQLite database that was opened with <a href="#db_open">db_open</a>.</summary>
 * <param name="db">The index of the database connection (returned by <a href="#db_open">db_open</a>)</param>
 * <returns>Returns the memory handle for a specified database.</returns>
 */
native DB_GetMemHandle(DB:db) = db_get_mem_handle;

/**
 * <library>omp_database</library>
 */
#pragma deprecated Use `DB_GetMemHandle`.
native db_get_mem_handle(DB:db);

/**
 * <library>omp_database</library>
 * <summary>Get <b>memory handle</b> for an SQLite query that was executed with <a href="#db_query">db_query</a>.</summary>
 * <param name="result">The index of the query (returned by <a href="#db_query">db_query</a>)</param>
 * <returns>Returns the memory handle for a specified query.</returns>
 */
native DB_GetLegacyDBResult(DBResult:result) = db_get_result_mem_handle;

/**
 * <library>omp_database</library>
 */
#pragma deprecated Use `DB_GetLegacyDBResult`.
native db_get_result_mem_handle(DBResult:result);

/**
 * <library>omp_database</library>
 */
native DB_GetDatabaseConnectionCount() = db_debug_openfiles;

/**
 * <library>omp_database</library>
 */
#pragma deprecated Use `DB_GetDatabaseConnectionCount`.
native db_debug_openfiles();

/**
 * <library>omp_database</library>
 */
native DB_GetDatabaseResultSetCount() = db_debug_openresults;

/**
 * <library>omp_database</library>
 */
#pragma deprecated Use `DB_GetDatabaseResultSetCount`.
native db_debug_openresults();
