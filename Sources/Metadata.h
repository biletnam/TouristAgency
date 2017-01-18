// ---------------------------------------------------------------------------

#ifndef MetadataH
#define MetadataH
// ---------------------------------------------------------------------------
#include <vector>
#include <system.hpp>
// ---------------------------------------------------------------------------
using namespace std;

// ---------------------------------------------------------------------------
struct TColumns {
	String DataField;
	String ListField;
	String KeyTable;
	String KeyField;
	bool Primary;
};

// ---------------------------------------------------------------------------
class TTable {
	friend class DBMetadata;

private:
	vector<TColumns>Columns;

public:
	String NameTable;
	bool ReadOnly;

	size_t size() const {
		return Columns.size();
	}

	const TColumns& operator[](unsigned n) const {
		return Columns[n];
	}
};

// ---------------------------------------------------------------------------
class DBMetadata {
private:
	vector<TTable>Tables;

public:
	DBMetadata();

	size_t size() const {
		return Tables.size();
	}

	const TTable& operator[](unsigned n) const {
		return Tables[n];
	}

private:
	void AddTable(const String &aNameTable) {
		TTable tmp;
		tmp.NameTable = aNameTable;
		tmp.ReadOnly = false;
		Tables.push_back(tmp);
	}

	void AddReport(const String &aNameTable) {
		TTable tmp;
		tmp.NameTable = aNameTable;
		tmp.ReadOnly = true;
		Tables.push_back(tmp);
	}

	void AddColumn(const String &aDataField) {
		TColumns tmp;
		tmp.DataField = aDataField;
		tmp.Primary = false;
		Tables.back().Columns.push_back(tmp);
	}

	void AddKey(const String &aDataField, const String &aListField,
		const String &aKeyTable, const String &aKeyField) {
		TColumns tmp;
		tmp.DataField = aDataField;
		tmp.ListField = aListField;
		tmp.KeyTable = aKeyTable;
		tmp.KeyField = aKeyField;
		tmp.Primary = true;
		Tables.back().Columns.push_back(tmp);
	}
};

// ---------------------------------------------------------------------------
extern const DBMetadata Mdata;
// ---------------------------------------------------------------------------
#endif
