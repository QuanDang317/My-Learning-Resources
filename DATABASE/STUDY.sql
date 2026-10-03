-- Create Schema study -- khoi tao schema
-- Drop Schema Study -- Xoa Schema
-- Phan quyen Schema
-- Grant Select|Insert|Update|Delete On Schema ::Study To Sql_Reader 

-- Tao Bang
-- Drop Table [study].[THONG_TIN_NV];
Create Table [study].[THONG_TIN_NV] ( -- neu co _ roi thi khong can []
	[MA_NV] VARCHAR(10) PRIMARY KEY, 
	[TEN_NV] NVARCHAR(30) DEFAULT N'QUAN DEP ZAI', 
	[TUOI] INT CHECK(TUOI >= 20) DEFAULT 30,
	[DOB] DATE NOT NULL
);
alter table study.THONG_TIN_NV
add emp_address NVARCHAR(200);

exec sp_rename 'study.THONG_TIN_NV', 'TT_NV'
--------------------------------------------------------------------

select *
from learn_csdl.dbo.khachhang

SELECT MA_KH,TEN_KHACH_HANG,DIA_CHI_KH 
FROM dbo.KhachHang;

SELECT * from dbo.HoaDon -- Lay xem full

SELECT 
MA_HOA_DON,
Year(NGAY_GIAO_DICH) as NAM_GD,
TRI_GIA,
PHAN_TRAM_HOA_HONG,
TRI_GIA*PHAN_TRAM_HOA_HONG/100 as HOA_HONG
from dbo.HoaDon
Where TRI_GIA*PHAN_TRAM_HOA_HONG/100 < 1000000
and YEAR(NGAY_GIAO_DICH) = 2019
or YEAR(NGAY_GIAO_DICH) = 2020
order by HOA_HONG desc -- sap xep giam dan, tang dan bo di 
;




